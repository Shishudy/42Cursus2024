/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 11:33:05 by rafasant          #+#    #+#             */
/*   Updated: 2025/08/17 19:16:10 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_simulation()
{
	pthread_mutex_lock(&context()->stop_lock);
	if (context()->stop)
	{
		pthread_mutex_unlock(&context()->stop_lock);
		return (1);
	}
	pthread_mutex_unlock(&context()->stop_lock);
	return (0);
}

int	check_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_lock);
	if ((get_time() - philo->started_eating) >= context()->time_to_die)
	{
		pthread_mutex_unlock(&philo->meal_lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->meal_lock);
	return (0);
}

int	check_meals(t_philo *philo)
{
	if (context()->number_of_times_each_philosopher_must_eat == -1)
		return (0);
	pthread_mutex_lock(&philo->meal_lock);
	if (philo->meals >= context()->number_of_times_each_philosopher_must_eat)
	{
		pthread_mutex_unlock(&philo->meal_lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->meal_lock);
	return (0);
}

int	check_philos()
{
	int	i;
	int	meals;

	i = 0;
	meals = 0;
	while (i < context()->number_of_philosophers)
	{
		if (check_time(&context()->arr_philos[i]))
		{
			perform_action(context()->arr_philos[i].philo_id, DEAD, 0);
			return (1);
		}
		else if (check_meals(&context()->arr_philos[i]))
		{
			meals++;
			if (meals == context()->number_of_philosophers)
				return (1);
		}
		i++;
	}
	return (0);
}

void	*overseer(void *arg)
{
	(void) arg;
	sim_start_delay(context()->start_time);
	while (1)
	{
		pthread_mutex_lock(&context()->stop_lock);
		if (check_philos())
		{
			context()->stop = 1;
			pthread_mutex_unlock(&context()->stop_lock);
			return (NULL);
		}
		pthread_mutex_unlock(&context()->stop_lock);
	}
	return (NULL);
}