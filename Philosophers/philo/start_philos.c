/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:23:01 by rafasant          #+#    #+#             */
/*   Updated: 2025/06/13 17:54:27 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

#include <time.h>

pthread_mutex_t	mutex;

void	print_msg(int i, char *msg)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	printf("%ld %d %s\n", (tv.tv_sec - (philos()->start_time)) * 1000, i, msg);
}

void	*philo_eating(void *arg)
{
	print_msg(*(int *)arg, "is eating");
	usleep(philos()->time_to_eat);
	return NULL;
}

void	*philo_thinking(void *arg)
{
	print_msg(*(int *)arg, "is thinking");
	return NULL;
}

void	*philo_sleeping(void *arg)
{
	print_msg(*(int *)arg, "is sleeping");
	usleep(philos()->time_to_sleep);
	return NULL;
}

void	sit_philos()
{
	int	i;

	i = 0;
	while (i < philos()->number_of_philosophers)
	{
		if (i % 2 == 0 && i + 1 != philos()->number_of_philosophers)
		{
			if (pthread_create(&philos()->arr_philos[i], NULL, &philo_eating, &i) != 0)
				return ((void) (catch()->error_msg = "Thread creation failure!"));
		}
		else
		{
			if (pthread_create(&philos()->arr_philos[i], NULL, &philo_thinking, &i) != 0)
				return ((void) (catch()->error_msg = "Thread creation failure!"));
		}
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