/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <rkost@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:19:02 by rkost             #+#    #+#             */
/*   Updated: 2023/12/28 12:03:37 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static long ft_char_to_int (char *str);
static bool is_space(char c);
static bool ft_check_arg(int args, char **arg);

t_arguments *ft_read_arguments(int args, char **arg)
{
    t_arguments *argument;

    if (ft_check_arg(args, arg) == false)
        return (NULL);
    argument = safe_malloc(sizeof(t_arguments), NULL);  
    //argument = malloc(sizeof(t_arguments));
    argument->l_nbr_philosopher = ft_char_to_int(arg[1]);
    argument->l_die_time = ft_char_to_int(arg[2]) * 1e3;
    argument->l_eat_time = ft_char_to_int(arg[3]) * 1e3;
    argument->l_sleep_time = ft_char_to_int(arg[4]) * 1e3;
    if (argument->l_die_time < 6e4 || argument ->l_eat_time < 6e4 
        || argument ->l_sleep_time <6e4)
    {
        ft_error(1, "Argument must be bigger then 59!", -1, NULL);
        return (NULL);
    }
    if (args == 6)
        argument->l_eat_must = ft_char_to_int(arg[5]);
    else 
        argument->l_eat_must = -1;
    return argument;
}

static bool ft_check_arg(int args, char **arg)
{
    int i_count;
    
    if (args < 5 || args > 6)
    {
        ft_error(1, "Wrong nummber of Arguments!\n", -1, NULL);
        return false;
    }
    i_count = 1;
    while (i_count < args)
    {
        if (ft_char_to_int(arg[i_count++]) ==  0)
        {
            ft_error(1, "Argument must be an Integer!", -1, NULL);
            return false;
        }
    }
    return true;
}

static long ft_char_to_int (char *str)
{
    int     i_count;
    unsigned long   l_ret; 

    l_ret = 0;
    i_count = 0;
    while (is_space(str[i_count]))
        i_count++;
    if (str[i_count] == '+')
        i_count++;
    while (str[i_count] != '\0')
    {
        if (str[i_count] >= '0' && str[i_count] <= '9')
            l_ret = (l_ret + (str[i_count++] - '0')) * 10;
        else
            return 0;
    }
    l_ret /= 10;
    if ((str[i_count] == '\0' && l_ret < 1) || (l_ret > INT_MAX))
        return 0;
    return (l_ret);
}

static bool is_space(char c)
{
    return ((c >= 9 && c <= 13) || c == 32);
}