#include "../includes/philosophers.h"

static  bool ft_philo_died(t_philo *philo);

void *ft_monitor_dinner(void *data)
{
    int i_count;
    t_arguments *argument;

    argument = (t_arguments *)data;

    while (!ft_all_threads_running(&argument->arguments_mutex, &argument->threads_running_nbr, argument->l_nbr_philosopher))
        ;

    while (!simualte_finished(argument))
    {
        i_count = -1;
            while (++i_count < argument->l_nbr_philosopher && !simualte_finished(argument))
            {
                if (ft_philo_died(argument->philos + i_count))
                {
                    set_bool(&argument->arguments_mutex, &argument->l_end_simulation, true);
                    write_status(DIED, argument->philos + i_count, DEBUG_MODE);
                }
            }
            
    }
    return (NULL);
}

static  bool ft_philo_died(t_philo *philo)
{
    long    elapsed;
    long    t_to_die;

    if (get_bool(&philo->philo_mutex, &philo->full))
        return (false);
    elapsed = gettime(MILLISECOND) - get_long(&philo->philo_mutex, &philo->last_meal_time);
    t_to_die = philo->arguments->l_die_time / 1e3;
    if (elapsed > t_to_die)
        return (true);
    return (false);

}