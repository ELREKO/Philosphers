/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <rkost@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:19:02 by rkost             #+#    #+#             */
/*   Updated: 2023/12/18 16:30:14 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

t_arguments *ft_read_arguments(int args, char **arg)
{
    t_arguments *argument;
    int i_count;

    i_count = 1;
    while (i_count < args)
    {
        if (ft_char_to_int(arg[i_count++]) ==  0)
            return NULL;
    }
    argument = malloc(sizeof(t_arguments));
    argument->l_nbr_philosopher = ft_char_to_int(arg[1]);
    argument->l_die_time = ft_char_to_int(arg[2]);
    argument->l_eat_time = ft_char_to_int(arg[3]);
    argument->l_sleep_time = ft_char_to_int(arg[4]);
    if (args == 6)
        argument->l_eat_must = ft_char_to_int(arg[5]);
    else 
        argument->l_eat_must = 0;
    return argument;
} 