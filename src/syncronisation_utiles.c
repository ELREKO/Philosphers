# include "../includes/philosophers.h"

void wait_all_threads(t_arguments *argument)
{
    while (!get_bool(&argument->arguments_mutex, &argument->all_threads_ready));
        ;    
}