#include "../includes/philosophers.h"

void *dinner_simulation(void *data)
{
    t_philo *philo;

    philo = (t_philo *)data; 
    wait_all_threads(philo->arguments);

    while (!simualte_finished(philo->arguments))
    {
        if (philo->full)
            break;
        // eat 

        // sleep 

        // thinking
    }
     

    return (NULL);

}
/*
* 0) If not meals, return ->[0]
* 1) If only one philo -> ad hoc function 
* 2) Each philo need a thread 
* 3) Use a monitor thread 
* 4) Synconisis the stradrt to all philo threads 
* 5) JOIN everyone 
*/

void dinner_start (t_arguments *argument)
{
    int i_count;

    i_count = -1;
    if (0 == argument->l_eat_must)
        return ;
    else if (1 == argument->l_nbr_philosopher)
        ; // Ad hoc function 
    else 
    {
        while (++i_count < argument->l_nbr_philosopher)
        {
            safe_thread_handel(&argument->philos[i_count].thread_id, dinner_simulation,
                &argument->philos[i_count], CREATE);
            printf("created philo %i\n", i_count);
            usleep(1);
        }
    }
    argument->l_start_simulation = gettime(MILLISECOND);
    //printf("%ld start time\n\n", argument->l_start_simulation);
    set_bool(&argument ->arguments_mutex, &argument->all_threads_ready, true);

    // wait for everyone 
    i_count = -1;
    while (++i_count < argument->l_nbr_philosopher)
    {
        safe_thread_handel(&argument->philos[i_count].thread_id, NULL, NULL, JOIN);
        printf("joined Philo %i\n", i_count);
    }
}