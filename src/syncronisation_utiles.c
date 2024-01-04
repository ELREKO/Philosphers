# include "../includes/philosophers.h"

void wait_all_threads(t_arguments *argument)
{
    while (!get_bool(&argument->arguments_mutex, &argument->all_threads_ready));
        ;    
}


bool ft_all_threads_running (t_mtx *mutex, long *therads, long philo_nbr)
{
    bool    ret;

    ret = false;
    safe_mutex_handel(mutex, LOCK);
    if ((*therads) == philo_nbr)
        ret = true;
    safe_mutex_handel(mutex, UNLOCK);
    return (ret);
}   


void ft_increase_long(t_mtx *mutex, long *value)
{
    safe_mutex_handel(mutex, LOCK);
    (*value)++;
    safe_mutex_handel(mutex, UNLOCK);
}


void ft_desyncronized_philos(t_philo *philo)
{
    if (philo->arguments->l_nbr_philosopher % 2 == 0)
	{
		if (philo->id % 2 == 0)
			precise_usleep(3e4, philo->arguments);
	}
	else
	{
		if (philo->id % 2)
			thinking(philo, true);
	}
}