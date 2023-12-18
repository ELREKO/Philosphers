/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <rkost@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:30:30 by rkost             #+#    #+#             */
/*   Updated: 2023/12/18 16:30:41 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int main(int args, char **arg)
{
    t_arguments *arguments;

    if (args < 5 || args > 6)
        ft_error(1, "Wrong nummber of Arguments!\n", 0, NULL);
    else
    {
        arguments = ft_read_arguments(args, arg);
        if (arguments == NULL)
            ft_error(1, "Arguments must be an Integer and biger then 0!\n", 0, NULL);
        else
            ft_print_arguments(arguments);
    }
}