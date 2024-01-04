/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <rkost@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:16:26 by rkost             #+#    #+#             */
/*   Updated: 2024/01/02 16:17:51 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

long gettime(t_time_code time_code)
{
    struct timeval tv;

    if (0 != gettimeofday(&tv, NULL))
        printf("Gettimeofday failled");
    if (SECOND == time_code)
        return (tv.tv_sec + (tv.tv_usec / 1e6));
    else if (MILLISECOND == time_code)
        return ((tv.tv_sec * 1e3) + (tv.tv_usec / 1e3));
    else if (MICROSECOND == time_code)
        return (tv.tv_usec + (tv.tv_sec * 1e6));
    else 
        printf("Wrong input to gettime");
    return (0);
}

void precise_usleep(long usec, t_arguments *argument)
{
    long start;
    long rem;

    start = gettime(MICROSECOND);
    while (gettime(MICROSECOND) - start < usec)
    {
        if (simualte_finished(argument))
            break;
        rem = usec - (gettime(MICROSECOND) - start);
        if (rem > 1e3)
            usleep(rem / 2);
        else
        {
            while (gettime(MICROSECOND) - start < usec)
                ;
        }
    }   
}


void ft_claen (t_arguments *argument)
{
    t_philo *philo; 
    int i_count;

    i_count = -1; 

    while (++i_count < argument->l_nbr_philosopher)
    {
        philo = argument->philos + i_count,
        safe_mutex_handel(&philo->philo_mutex, DESTROY);
    }
    safe_mutex_handel(&argument->write_mutex, DESTROY);
    safe_mutex_handel(&argument->arguments_mutex, DESTROY);
    free(argument->forks);
    free(argument->philos);
}


void ft_print_arguments(t_arguments *arg)
{
    printf("Nummer of Philosphers: %ld\n", arg->l_nbr_philosopher);
    printf("Time to die: %ld\n", arg->l_die_time);
    printf("Time to eat: %ld\n", arg->l_eat_time);
    printf("Time to sleep: %ld\n", arg->l_sleep_time);
    printf("Nummer of Time Philsophers musst eat: %ld\n", arg->l_eat_must);
}