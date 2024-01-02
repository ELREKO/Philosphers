#include "../includes/philosophers.h"

static void	write_status_debug(t_philo_status status, t_philo *philo,
		long elapsed);


void	write_status(t_philo_status status, t_philo *philo, bool debug)
{
	long	elapsed;

	elapsed = gettime(MILLISECOND) - philo->arguments->l_start_simulation;
	if (get_bool(&philo->philo_mutex, &philo->full))
		return ;
	safe_mutex_handel(&philo->arguments->write_mutex, LOCK);
	if (debug)
		write_status_debug(status, philo, elapsed);
	else
	{
		if ((TAKE_FIRST_FORK == status || TAKE_SECOND_FORK == status)
			&& !simualte_finished(philo->arguments))
			printf("%-6ld %d has taken a fork\n", elapsed, philo->id);
		else if (EATING == status && !simualte_finished(philo->arguments))
			printf("%-6ld %d is eating\n", elapsed, philo->id);
		else if (SLEEPING == status && !simualte_finished(philo->arguments))
			printf("%-6ld %d is sleeping\n", elapsed, philo->id);
		else if (THINKING == status && !simualte_finished(philo->arguments))
			printf("%-6ld %d is thinking\n", elapsed, philo->id);
		else if (DIED == status)
			printf("%-6ld %d died\n", elapsed, philo->id);
	}
	safe_mutex_handel(&philo->arguments->write_mutex, UNLOCK);
}

static void	write_status_debug(t_philo_status status, t_philo *philo,
		long elapsed)
{
	if (TAKE_FIRST_FORK == status && !simualte_finished(philo->arguments))
		printf("%6ld %d has taken the 1° fork 🍽 "
			"\t\t\tn° [🍴 %d 🍴]\n", elapsed, philo->id,
			philo->first_fork->fork_id);
	else if (TAKE_SECOND_FORK == status && !simualte_finished(philo->arguments))
		printf("%6ld %d has taken the 2° fork 🍽"
			"\t\t\tn° [🍴 %d 🍴]\n", elapsed, philo->id,
			philo->second_fork->fork_id);
	else if (EATING == status && !simualte_finished(philo->arguments))
		printf("%6ld %d is eating 🍝"
			"\t\t\t [🍝 %ld 🍝]\n", elapsed, philo->id, philo->meals_counter);
	else if (SLEEPING == status && !simualte_finished(philo->arguments))
		printf("%6ld %d is sleeping 😴\n", elapsed, philo->id);
	else if (THINKING == status && !simualte_finished(philo->arguments))
		printf("%6ld %d is thinking 🤔\n", elapsed, philo->id);
	else if (DIED == status)
		printf("\t\t💀💀💀 %6ld %d died   💀💀💀 :smili: \n", elapsed, philo->id);
}