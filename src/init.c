#include "../includes/philosophers.h"
static void philo_init(t_arguments *argument);
static void assign_forks(t_philo *philo, t_fork *forks, int philo_position);

void init_data(t_arguments *argument)
{
    int i_count;

    i_count = -1;
    argument ->l_end_simulation = false;
    argument->all_threads_ready = false;
    argument->threads_running_nbr = 0;
    argument ->forks = safe_malloc(sizeof(t_fork) * argument->l_nbr_philosopher, argument);
    argument ->philos = safe_malloc(sizeof(t_philo) * argument ->l_nbr_philosopher , argument);
    safe_mutex_handel(&argument->arguments_mutex, INIT);
    safe_mutex_handel(&argument->write_mutex, INIT);
    while (++i_count < argument->l_nbr_philosopher)
    {
        safe_mutex_handel(&argument->forks[i_count].fork, INIT);
        argument ->forks[i_count].fork_id = i_count;
        printf("Fork nbr %d is her \n", argument ->forks[i_count].fork_id);
    }
    philo_init(argument);

    // i_count = 0;
    // printf("which forks\n");
    // while (argument ->forks[i_count].fork_id)
    // {
    //     printf("Fork nbr %ld is her \n", argument ->forks[i_count].fork_id);
    // }
    
}

static void philo_init(t_arguments *argument)
{
    int i_count;
    t_philo *philo;

    i_count = -1;
    while (++i_count < argument ->l_nbr_philosopher)
    {
        philo = argument->philos + i_count;
        philo->id = i_count + 1;
        philo-> full = false; 
        philo->meals_counter = 0;
        safe_mutex_handel(&philo->philo_mutex, INIT);
        philo->arguments = argument;
        assign_forks(philo, argument->forks, i_count);
    }
}

static void assign_forks(t_philo *philo, t_fork *forks, int philo_position)
{
	int	philo_nbr;

	philo_nbr = philo->arguments->l_nbr_philosopher;
	philo->first_fork = &forks[(philo_position + 1) % philo_nbr];
	philo->second_fork = &forks[philo_position];
	if (philo->id % 2 == 0)
	{
		philo->first_fork = &forks[philo_position];
		philo->second_fork = &forks[(philo_position + 1) % philo_nbr];
	}	
}