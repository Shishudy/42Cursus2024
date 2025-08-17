/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:25:24 by rafasant          #+#    #+#             */
/*   Updated: 2025/08/17 17:38:26 by rafasant         ###   ########.fr       */
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
	else if (philo->philo_id % 2 != 0)
	{
		if (eating_odd(philo))
			return (1);
	}
	pthread_mutex_lock(&philo->meal_lock);
	philo->started_eating = get_time();
	if (perform_action(philo->philo_id, EATING, context()->time_to_eat))
	{
		pthread_mutex_unlock(&philo->meal_lock);
		return (1);
	}
	philo->meals++;
	pthread_mutex_unlock(&philo->meal_lock);
	return (stop_eating(philo), 0);
}