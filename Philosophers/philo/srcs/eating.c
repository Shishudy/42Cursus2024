/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:25:24 by rafasant          #+#    #+#             */
/*   Updated: 2025/08/20 20:19:22 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	eating_even(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_right);
	if (perform_action(philo->philo_id, GRAB, 0))
	{
		pthread_mutex_unlock(philo->fork_right);
		return (1);
	}
	pthread_mutex_lock(&philo->fork_left);
	if (perform_action(philo->philo_id, GRAB, 0))
	{
		pthread_mutex_unlock(philo->fork_right);
		pthread_mutex_unlock(&philo->fork_left);
		return (1);
	}
	return (0);
}

int	eating_odd(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork_left);
	if (perform_action(philo->philo_id, GRAB, 0))
	{
		pthread_mutex_unlock(&philo->fork_left);
		return (1);
	}
	pthread_mutex_lock(philo->fork_right);
	if (perform_action(philo->philo_id, GRAB, 0))
	{
		pthread_mutex_unlock(&philo->fork_left);
		pthread_mutex_unlock(philo->fork_right);
		return (1);
	}
	return (0);
}

void	stop_eating(t_philo *philo)
{
	if (philo->philo_id % 2 == 0)
	{
		pthread_mutex_unlock(&philo->fork_left);
		pthread_mutex_unlock(philo->fork_right);
	}
	else if (philo->philo_id % 2 != 0)
	{
		pthread_mutex_unlock(philo->fork_right);
		pthread_mutex_unlock(&philo->fork_left);
	}
}

int	eating(t_philo *philo)
{
	if (philo->philo_id % 2 == 0)
	{
		if (eating_even(philo))
			return (1);
	}
	else
	{
		if (eating_odd(philo))
			return (1);
	}
	if (check_simulation())
		return (stop_eating(philo), 1);
	pthread_mutex_lock(&philo->meal_lock);
	philo->started_eating = get_time();
	philo->meals++;
	pthread_mutex_unlock(&philo->meal_lock);
	if (perform_action(philo->philo_id, EATING, context()->time_to_eat))
		return (stop_eating(philo), 1);
	return (stop_eating(philo), 0);
}
