/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:23:01 by rafasant          #+#    #+#             */
/*   Updated: 2025/08/08 16:15:17 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

pthread_mutex_t	mutex;

int	print_msg(int i, int action)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	if (action == GRAB)
		printf("%ld %d has taken a fork\n", \
			(tv.tv_sec - (context()->start_time)) * 1000, i);
	else if (action == EATING)
		printf("%ld %d is eating\n", \
			(tv.tv_sec - (context()->start_time)) * 1000, i);
	else if (action == SLEEPING)
		printf("%ld %d is sleeping\n", \
			(tv.tv_sec - (context()->start_time)) * 1000, i);
	else if (action == THINKING)
		printf("%ld %d is thinking\n", \
			(tv.tv_sec - (context()->start_time)) * 1000, i);
	else if (action == DEAD)
		printf("%ld %d died\n", \
			(tv.tv_sec - (context()->start_time)) * 1000, i);
	return (1);
}

int	take_forks(t_philo *philo)
{
	int	status;

	if (philo->philo_id % 2 == 0)
	{
		status = pthread_mutex_lock(&philo->fork_left);
		if (status != 0)
			return (status);
		print_msg(philo->philo_id, GRAB);
		status = pthread_mutex_lock(&philo->fork_right);
		if (status != 0)
			return (status);
		print_msg(philo->philo_id, GRAB);
	}
	return (0);
}

void	*eat_sleep_think(void *arg)
{
	t_philo		*philo;
	time_t		result;
	time_t		after_eating;
	time_t		before_eating;
	struct timeval	tv;

	philo = (t_philo *)arg;
	while (1)
	{
		// if (take_forks(philo))
		// 	return (catch()->error_msg = "Error on take_forks for philo {philo_id}!", NULL);

		// pthread_mutex_lock(&philo->fork1);
		// print_msg(philo->philo_id, GRAB);
		// pthread_mutex_lock(&philo->fork2);
		// print_msg(philo->philo_id, GRAB);
		// print_msg(philo->philo_id, EATING);
		// philo->internal_timer = 0;
		// result = philo->internal_timer + context()->time_to_eat; //tenho de ajustar para o tipo de varivel de tmepos bater certo, o valor resltante de gettimeofday e time_to_die sao diffs
		// if (result > philo->internal_timer + context()->time_to_die)
		// {
		// 	usleep(result);
		// 	print_msg(philo->philo_id, DEAD);
		// 	pthread_mutex_unlock(&philo->fork1);
		// 	pthread_mutex_unlock(&philo->fork2);
		// 	return ;
		// }
		// else
		// 	usleep(context()->time_to_eat);
		// pthread_mutex_unlock(&philo->fork1);
		// pthread_mutex_unlock(&philo->fork2);
		// print_msg(philo->philo_id, SLEEPING);
		// philo->started_sleeping = gettimeofday(&tv, NULL);
		// if (context()->time_to_die < context()->time_to_eat)
		// 	usleep(context()->time_to_sleep);
		// print_msg(philo->philo_id, THINKING);
	}
	return (NULL);
}

void	singular_philo()
{
	pthread_mutex_lock(&context()->arr_philos[0].fork_left);
	print_msg(1, GRAB);
	pthread_mutex_unlock(&context()->arr_philos[0].fork_left);
	print_msg(1, DEAD);
}

void	sit_philos()
{
	int	i;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	context()->start_time = tv.tv_sec;
	if (context()->number_of_philosophers == 1)
		return (singular_philo());
	i = 0;
	while (i < context()->number_of_philosophers)
	{ 
		if (pthread_create(&context()->arr_philos[i].philo_th, NULL, &eat_sleep_think, &context()->arr_philos[i]) != 0)
			return ((void) (catch()->set_error("%s: Thread creation failure!", __func__)));
		i++;
	}
	i = 0;
	while (i < context()->number_of_philosophers)
	{
		if (pthread_join(context()->arr_philos[i].philo_th, NULL) != 0)
			return ((void) (catch()->set_error("%s: Thread join failure!", __func__)));
		i++;
	}
}

void	prepare_philos()
{
	int	i;

	i = 0;
	while (i < context()->number_of_philosophers)
	{
		context()->arr_philos[i].philo_id = i + 1;
		context()->arr_philos[i].internal_timer = 0;
		context()->arr_philos[i].started_eating = 0;
		context()->arr_philos[i].started_sleeping = 0;
		context()->arr_philos[i].philo_th = 0;
		context()->arr_philos[i].fork_right = NULL;
		if (pthread_mutex_init(&context()->arr_philos[i].fork_left, NULL) != 0)
			return ((void) (catch()->set_error("%s: Malloc failure!", __func__)));
		if (i > 0)
			context()->arr_philos[i - 1].fork_right = &context()->arr_philos[i].fork_left;
		if (context()->number_of_philosophers != 1 && i + 1 == context()->number_of_philosophers)
			context()->arr_philos[i].fork_right = &context()->arr_philos[0].fork_left;
		i++;
	}
}

void	start_philos()
{
	int	i;

	context()->arr_philos = malloc(sizeof(t_philo) * context()->number_of_philosophers);
	if (!context()->arr_philos)
		return ((void) (catch()->set_error("%s: Malloc failure!", __func__)));
	prepare_philos();
	sit_philos();
	pthread_mutex_destroy(&mutex);
}