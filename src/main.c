/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <rkost@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:30:30 by rkost             #+#    #+#             */
/*   Updated: 2024/01/02 13:04:01 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int main(int args, char **arg)
{
    t_arguments *arguments;
    
    arguments = ft_read_arguments(args, arg);



    
    if (arguments != NULL)
    {
        init_data(arguments);
        dinner_start(arguments);

        ft_print_arguments(arguments);
        free(arguments->forks);
        free(arguments->philos);
        free(arguments);
    }
}