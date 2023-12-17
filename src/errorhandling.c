#include "../includes/philosophers.h"

static void ft_put_string(char *str);


/*
- del -> 0 -> noting to delete or to free
*/
void ft_error(int err_nbr, char *msg, int del, t_arguments **arg)
{
    if (err_nbr == 1)
        ft_put_string(msg);
    if (del == 1)
        free(arg);
        
}

static void ft_put_string(char *str)
{
    int i_count; 

    i_count = 0;
    while (str[i_count] != '\0')
        write(1, &str[i_count++], 1);
}