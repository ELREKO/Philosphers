#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h> 	// malloc free
# include <unistd.h> 	// write usleep
# include <stdio.h> 	// printf
# include <stdbool.h>	
# include <pthread.h>	// mutex: init destroy unlock
						// threads : create join detach 
# include <sys/time.h>	// gettimeofday
# include <limits.h>	// INT_MAX
# include <errno.h>
# include <time.h>

# ifndef DEBUG_MODE
#  define DEBUG_MODE 0
# endif

# ifndef PHILO_MAX
#  define PHILO_MAX 200 
# endif


typedef struct s_philo t_philo;
typedef struct s_fork t_fork;
typedef pthread_mutex_t t_mtx;

typedef enum e_opccode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
} t_opccode;

typedef enum e_time_code
{
	SECOND,
	MILLISECOND,
	MICROSECOND,
} t_time_code;

typedef enum e_staus_philo
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK,
	DIED,
}	t_philo_status;

typedef struct s_stack 
{
	 long	l_nbr_philosopher; //number_of_philosophers
	 long	l_die_time; // time to die
	 long   l_eat_time; // time to eat
	 long   l_sleep_time; //time to sleep
     long   l_eat_must; // number_of_times_each_philosopher_must_eat
	 long	l_start_simulation;
	 bool 	l_end_simulation;
	 bool	all_threads_ready;
	 t_mtx	arguments_mutex;
	 t_mtx	write_mutex;
	t_fork			*forks; // array of forks
	t_philo 		*philos; //arry of philosophers
} t_arguments;

typedef struct s_philo
{
	int			id;
	long		meals_counter;
	bool		full;
	long		last_meal_time;  //time passed from last meal
	t_fork		*first_fork;
	t_fork		*second_fork;
	pthread_t	thread_id;
	t_mtx		philo_mutex;
	t_arguments *arguments;
} t_philo;

/*
* FORK
*/
typedef struct s_fork
{
	t_mtx 	fork;
	int		fork_id;
}  t_fork;

// checking_arguments.c 
t_arguments *ft_read_arguments(int args, char **arg);

// dinner.c 
void dinner_start (t_arguments *argument);

// errorhandling.c
void ft_error(int err_nbr, char *msg, int del, t_arguments **arg);

// getter_setter.c 
void set_bool(t_mtx *mutex, bool *dest, bool value);
bool get_bool(t_mtx *mutex, bool *value);
void set_long(t_mtx *mutex, long *dest, long value);
long get_long(t_mtx *mutex, long *value);
bool    simualte_finished (t_arguments *argument);

// init.c
void init_data(t_arguments *data);

// safer function.c 
void *safe_malloc(size_t bytes, t_arguments *args);
void safe_mutex_handel(t_mtx *mutex, t_opccode opcode);
void safe_thread_handel(pthread_t *thread, void *(foo)(void *), void *data, t_opccode opcode);

// syncronisation_utiles.c
void wait_all_threads(t_arguments *argument);

// utiles.c
long gettime(t_time_code time_code);
void precise_usleep(long usec, t_arguments *argument);
void ft_print_arguments(t_arguments *arg);

// write.c 

void	write_status(t_philo_status status, t_philo *philo, bool debug);

#endif