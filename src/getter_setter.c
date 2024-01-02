#include "../includes/philosophers.h"

void set_bool(t_mtx *mutex, bool *dest, bool value)
{
    safe_mutex_handel(mutex, LOCK);
    *dest = value;
    safe_mutex_handel(mutex, UNLOCK);

}

bool get_bool(t_mtx *mutex, bool *value)
{
    bool ret; 

    safe_mutex_handel(mutex, LOCK);
    ret = *value;
    safe_mutex_handel(mutex, UNLOCK);
    return (ret);
}

void set_long(t_mtx *mutex, long *dest, long value)
{
    safe_mutex_handel(mutex, LOCK);
    *dest = value;
    safe_mutex_handel(mutex, UNLOCK);

}

long get_long(t_mtx *mutex, long *value)
{
    long ret; 

    safe_mutex_handel(mutex, LOCK);
    ret = *value;
    safe_mutex_handel(mutex, UNLOCK);
    return (ret);
}


bool    simualte_finished (t_arguments *argument)
{
    return (get_bool(&argument->arguments_mutex, &argument ->l_end_simulation));
}


