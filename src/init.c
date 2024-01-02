#include "../includes/philosophers.h"
static void philo_init(t_arguments *data);
static void assign_forks(t_philo *philo, t_fork *forks, int philo_position);

void init_data(t_arguments *data)
{
    int i_count;

    i_count = -1;
    data ->l_end_simulation = false;
    data ->forks = safe_malloc(sizeof(t_fork) * data->l_nbr_philosopher, data);
    data ->philos = safe_malloc(sizeof(t_philo) * data ->l_nbr_philosopher , data);
    safe_mutex_handel(&data->arguments_mutex, INIT);
    safe_mutex_handel(&data->write_mutex, INIT);
    while (++i_count < data->l_nbr_philosopher)
    {
        safe_mutex_handel(&data->forks[i_count].fork, INIT);
        data ->forks[i_count].fork_id = i_count;
    }
    philo_init(data);
}

static void philo_init(t_arguments *data)
{
    int i_count;
    t_philo *philo;

    i_count = -1;
    while (++i_count < data ->l_nbr_philosopher)
    {
        philo = data->philos + i_count;
        philo->id = i_count + 1;
        philo-> full = false; 
        philo->meals_counter = 0;
        safe_mutex_handel(&philo->philo_mutex, INIT);
        philo->arguments = data;
        assign_forks(philo, data->forks, i_count);
    }
}

static void assign_forks(t_philo *philo, t_fork *forks, int philo_position)
{
    int	philo_nbr;

	philo_nbr = philo->arguments->l_nbr_philosopher;
	if (philo->id % 2 == 0)
	{
		philo->first_fork = &forks[philo_position];
		philo->second_fork = &forks[(philo_position - 1) % philo_nbr];
	}
    else
    {
	    philo->first_fork = &forks[(philo_position - 1) % philo_nbr];
	    philo->second_fork = &forks[philo_position];
    }
}