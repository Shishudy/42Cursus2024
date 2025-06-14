/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:23:01 by rafasant          #+#    #+#             */
/*   Updated: 2025/06/14 18:40:33 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

#include <time.h>

pthread_mutex_t	mutex;

void	print_msg(int i, int action)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	if (action == GRAB)
		printf("%ld %d has taken a fork\n", \
			(tv.tv_sec - (philos()->start_time)) * 1000, i);
	else if (action == EATING)
		printf("%ld %d is eating\n", \
			(tv.tv_sec - (philos()->start_time)) * 1000, i);
	else if (action == SLEEPING)
		printf("%ld %d is sleeping\n", \
			(tv.tv_sec - (philos()->start_time)) * 1000, i);
	else if (action == THINKING)
		printf("%ld %d is thinking\n", \
			(tv.tv_sec - (philos()->start_time)) * 1000, i);
	else if (action == DEAD)
		printf("%ld %d died\n", \
			(tv.tv_sec - (philos()->start_time)) * 1000, i);

}

void	*eat_sleep_think(void *arg)
{
	t_sphilo	*sphilo;
	time_t		result;
	time_t		after_eating;
	time_t		before_eating;
	struct timeval	tv;

	sphilo = (t_sphilo *)arg;
	while (1)
	{
		pthread_mutex_lock(&sphilo->fork1);
		print_msg(sphilo->philo_id, GRAB);
		pthread_mutex_lock(&sphilo->fork2);
		print_msg(sphilo->philo_id, GRAB);
		print_msg(sphilo->philo_id, EATING);
		sphilo->internal_timer = 0;
		result = sphilo->internal_timer + philos()->time_to_eat; //tenho de ajustar para o tipo de varivel de tmepos bater certo, o valor resltante de gettimeofday e time_to_die sao diffs
		if (result > sphilo->internal_timer + philos()->time_to_die)
		{
			usleep(result);
			print_msg(sphilo->philo_id, DEAD);
			pthread_mutex_unlock(&sphilo->fork1);
			pthread_mutex_unlock(&sphilo->fork2);
			return ;
		}
		else
			usleep(philos()->time_to_eat);
		pthread_mutex_unlock(&sphilo->fork1);
		pthread_mutex_unlock(&sphilo->fork2);
		print_msg(sphilo->philo_id, SLEEPING);
		sphilo->started_sleeping = gettimeofday(&tv, NULL);
		if (philos()->time_to_die < philos()->time_to_eat)
			usleep(philos()->time_to_sleep);
		print_msg(sphilo->philo_id, THINKING);



	}
}

void	sit_philos()
{
	int	i;

	i = 0;
	while (i < philos()->number_of_philosophers)
	{ 
		if (pthread_create(&philos()->arr_philos[i].philo, NULL, &eat_sleep_think, &philos()->arr_philos[i]) != 0)
			return ((void) (catch()->error_msg = "Thread creation failure!"));
		i++;
	}
	i = 0;
	while (i < philos()->number_of_philosophers)
	{
		if (pthread_join(philos()->arr_philos[i], NULL) != 0)
			return ((void) (catch()->error_msg = "Thread join failure!"));
		// printf("%d has finished and returned [%d]\n", i, *res);
		i++;
	}
}

void	start_philos()
{
	srand(time(NULL));
	philos()->arr_philos = malloc(sizeof(pthread_t) * philos()->number_of_philosophers);
	if (!philos()->arr_philos)
		return ((void) (catch()->error_msg = "Malloc failure!"));
	pthread_mutex_init(&mutex, NULL);
	sit_philos();
	pthread_mutex_destroy(&mutex);
}