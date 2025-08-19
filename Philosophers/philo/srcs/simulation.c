/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:23:01 by rafasant          #+#    #+#             */
/*   Updated: 2025/08/19 21:12:31 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	thinking(t_philo *philo)
{
	// time_t	think_time;

	if (check_simulation())
		return (1);
	// pthread_mutex_lock(&philo->meal_lock);
// 	think_time = context()->time_to_die - context()->time_to_eat - 
// context()->time_to_sleep;
// 	pthread_mutex_unlock(&philo->meal_lock);
// 	if (think_time < 0)
// 		think_time = 0;
	return (perform_action(philo->philo_id, THINKING, 0));
}

int	sleeping(t_philo *philo)
{
	if (check_simulation())
		return (1);
	return (perform_action(philo->philo_id, SLEEPING, \
context()->time_to_sleep));
}

void	singular_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork_left);
	perform_action(1, GRAB, context()->time_to_die);
	pthread_mutex_unlock(&philo->fork_left);
	perform_action(1, DEAD, 0);
}

void	*eat_sleep_think(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (context()->number_of_philosophers == 1)
		return (singular_philo(philo), NULL);
	sim_start_delay(context()->start_time);
	if (philo->philo_id % 2 == 0)
		usleep(context()->time_to_eat * 1000);
	while (!check_simulation())
	{
		if (eating(philo))
			break ;
		if (sleeping(philo))
			break ;
		if (thinking(philo))
			break ;
	}
	return (NULL);
}

void	run_simulation(void)
{
	int	i;

	i = 0;
	while (i < context()->number_of_philosophers)
	{
		if (pthread_create(&context()->arr_philos[i].philo_th, NULL, \
eat_sleep_think, &context()->arr_philos[i]) != 0)
			return ((void)(catch()->set("%s: Thread creation failure!", \
__func__)));
		i++;
	}
	if (pthread_create(&context()->overseer, NULL, overseer, NULL) != 0)
		return ((void)(catch()->set("%s: Thread creation failure!", \
__func__)));
	i = 0;
	while (i < context()->number_of_philosophers)
	{
		if (pthread_join(context()->arr_philos[i].philo_th, NULL) != 0)
			return ((void)(catch()->set("%s: Thread join failure!", \
__func__)));
		i++;
	}
	if (pthread_join(context()->overseer, NULL) != 0)
		return ((void)(catch()->set("%s: Thread join failure!", \
__func__)));
}
