/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <rkost@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:16:26 by rkost             #+#    #+#             */
/*   Updated: 2023/12/28 13:38:47 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void ft_print_arguments(t_arguments *arg)
{
    printf("Nummer of Philosphers: %ld\n", arg->l_nbr_philosopher);
    printf("Time to die: %ld\n", arg->l_die_time);
    printf("Time to eat: %ld\n", arg->l_eat_time);
    printf("Time to sleep: %ld\n", arg->l_sleep_time);
    printf("Nummer of Time Philsophers musst eat: %ld\n", arg->l_eat_must);
}