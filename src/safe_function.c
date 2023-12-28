# include "../includes/philosophers.h"
static void handel_mutex_err(int status, t_opccode opccode);
static void handel_thread_err(int status, t_opccode opcode);

void *safe_malloc(size_t bytes, t_arguments *args)
{
    void *ret;
    ret = malloc(bytes);
    if (ret == NULL)
        ft_error(1, "Error during malloc", 1, &args);
    return ret;
}

void safe_mutex_handel(t_mtx *mutex, t_opccode opcode)
{
    if (LOCK == opcode)
        handel_mutex_err(pthread_mutex_lock(mutex), opcode);
    else if (UNLOCK == opcode)
        handel_mutex_err(pthread_mutex_unlock(mutex), opcode);
    else if (INIT == opcode)
        handel_mutex_err(pthread_mutex_init(mutex, NULL), opcode);
    else if (DESTROY == opcode)
        handel_mutex_err(pthread_mutex_destroy(mutex), opcode);
    else 
        ft_error(1, "Wrong Mutex opcode", -1, NULL); 
}

void safe_thread_handel(pthread_t *thread, void *(foo)(void *), void *data, t_opccode opcode)
{
    if (CREATE == opcode)
        handel_thread_err(pthread_create(thread, NULL, foo, data), opcode);
    else if (JOIN == opcode)
        handel_thread_err(pthread_join(*thread, NULL), opcode);
    else if (DESTROY == opcode)
        handel_thread_err(pthread_detach(*thread), opcode);
    else 
        ft_error(1, "Wrong thread opcode", -1, NULL); 
}

static void handel_thread_err(int status, t_opccode opcode)
{
    if (0 == status)
        return ;
    if (EAGAIN == status)
        printf("No resources to create a other therad. \n"); 
    else if (EPERM == status)
        printf("No permission to set the scheduling policy and parameters specified in attr.\n"); 
    else if (EINVAL == status && CREATE == opcode)
        printf("Invalid settings in attr.\n"); 
    else if (EINVAL == status && (JOIN == opcode || DETACH == opcode))
        printf ("Another thread is already waiting to join with this thread.\n");
    else if (ESRCH == status)
        printf ("No thread with the ID thread could be found.\n");
    else if (EDEADLK == status)
        printf ("A  deadlock  was  detected (e.g., two threads tried to join with each other); or thread specifies the calling thread.\n");
}

static void handel_mutex_err(int status, t_opccode opccode)
{
    if (0 == status)
        return ;
    if (EINVAL == status && (LOCK == opccode || UNLOCK == opccode))
        printf("The value specified by mutex is invalid.\n"); 
    else if (EINVAL == status && INIT == opccode)
        printf("value specified by attr is invalid.\n"); 
    else if (EDEADLK == status)
        printf("A deadlock would occur if the thread blocked waiting for mutex.\n"); 
    else if (EPERM == status)
        printf ("Current thread does not hold a lock on mutex.\n");
    else if (ENOMEM == status)
        printf ("Process cannot alloate enough memory to create a another mutex.\n");
    else if (EBUSY == status)
        printf ("Mutex is locked.\n");
}