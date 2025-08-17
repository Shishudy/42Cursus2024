/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:29:24 by rafasant          #+#    #+#             */
/*   Updated: 2025/08/17 19:24:31 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_action(int philo_id, int action)
{
	pthread_mutex_lock(&context()->print_lock);
	if (action == GRAB)
		printf("%ld %d has taken a fork\n", \
			(get_time() - (context()->start_time)), philo_id);
	else if (action == EATING)
		printf("%ld %d is eating\n", \
			(get_time() - (context()->start_time)), philo_id);
	else if (action == SLEEPING)
		printf("%ld %d is sleeping\n", \
			(get_time() - (context()->start_time)), philo_id);
	else if (action == THINKING)
		printf("%ld %d is thinking\n", \
			(get_time() - (context()->start_time)), philo_id);
	else if (action == DEAD)
		printf("%ld %d died\n", \
			(get_time() - (context()->start_time)), philo_id);
	pthread_mutex_unlock(&context()->print_lock);
}

void	print_death(int philo_id)
{
	// pthread_mutex_lock(&context()->print_lock);
	printf("%ld %d died\n", \
			(get_time() - (context()->start_time)), philo_id);
	// pthread_mutex_unlock(&context()->print_lock);
}

int	perform_action(int philo_id, int action, time_t action_time)
{
	time_t	finish;

	if (action == DEAD)
		return (print_death(philo_id), 1);
	if (action != DEAD && check_simulation())
		return (1);
	print_action(philo_id, action);
	if (action_time == 0)
		return (0);
	finish = get_time() + action_time;
	while (get_time() < finish)
		usleep(1);
	return (0);
}
