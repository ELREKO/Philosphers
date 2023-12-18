#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack 
{
	unsigned long	l_nbr_philosopher; //number_of_philosophers
	unsigned long	l_die_time; // time to die
	unsigned long   l_eat_time; // time to eat
	unsigned long   l_sleep_time; //time to sleep
    unsigned long   l_eat_must; // number_of_times_each_philosopher_must_eat
} t_arguments;

// checking_arguments.c 
t_arguments *ft_read_arguments(int args, char **arg);

// errorhandling.c
void ft_error(int err_nbr, char *msg, int del, t_arguments **arg);

// utiles.c
long ft_char_to_int(char *str);
void ft_print_arguments(t_arguments *arg);
#endif