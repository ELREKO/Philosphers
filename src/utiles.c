/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <rkost@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:16:26 by rkost             #+#    #+#             */
/*   Updated: 2023/12/18 16:38:45 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

long ft_char_to_int (char *str)
{
    int     i_count;
    unsigned long   l_ret; 

    l_ret = 0;
    i_count = 0; 
    while (str[i_count] != '\0')
    {
        if (str[i_count] >= '0' && str[i_count] <= '9')
            l_ret = (l_ret + (str[i_count++] - '0')) * 10;
        else
            return 0;
    }
    if (str[i_count] == '\0' && l_ret < 1)
        return 0;
    l_ret /= 10;
    return l_ret;
}

void ft_print_arguments(t_arguments *arg)
{
    printf("Nummer of Philosphers: %ld\n", arg->l_nbr_philosopher);
    printf("Time to die: %ld\n", arg->l_die_time);
    printf("Time to eat: %ld\n", arg->l_eat_time);
    printf("Time to sleep: %ld\n", arg->l_sleep_time);
    printf("Nummer of Time Philsophers musst eat: %ld\n", arg->l_eat_must);
}