/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_philos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:42:08 by rafasant          #+#    #+#             */
/*   Updated: 2025/08/20 20:17:45 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_params(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return ((void)\
(catch()->set("%s: Argument [%d] has invalid character [%c]", __func__, \
i, argv[i][j])));
			j++;
		}
		i++;
	}
}

void	assign_value(int n, int i)
{
	if (i == 1)
		context()->number_of_philosophers = n;
	else if (i == 2)
		context()->time_to_die = n;
	else if (i == 3)
		context()->time_to_eat = n;
	else if (i == 4)
		context()->time_to_sleep = n;
	else if (i == 5)
		context()->number_of_times_each_philosopher_must_eat = n;
}

void	parse_params(char **argv)
{
	int		i;
	int		j;
	long	n;

	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		n = 0;
		while (argv[i][j] != '\0')
		{
			n = n * 10 + (argv[i][j] - 48);
			if (n > __INT_MAX__)
				return ((void)(catch()->set("%s: Invalid number!", __func__)));
			j++;
		}
		assign_value(n, i);
		i++;
	}
	if (context()->number_of_philosophers < 1)
		return ((void)(catch()->set("%s: Invalid number of philos", __func__)));
	if (i == 5)
		context()->number_of_times_each_philosopher_must_eat = -1;
}

void	init_philos(void)
{
	int	i;

	i = 0;
	while (i < context()->number_of_philosophers)
	{
		context()->arr_philos[i].philo_id = i + 1;
		context()->arr_philos[i].meals = 0;
		context()->arr_philos[i].started_eating = context()->start_time;
		memset(&context()->arr_philos[i].philo_th, '\0', sizeof(pthread_t));
		context()->arr_philos[i].fork_right = NULL;
		if (pthread_mutex_init(&context()->arr_philos[i].meal_lock, NULL) != 0)
			return ((void)(catch()->set("%s: Mutex init error!", __func__)));
		if (pthread_mutex_init(&context()->arr_philos[i].fork_left, NULL) != 0)
			return ((void)(catch()->set("%s: Mutex init error!", __func__)));
		if (i > 0)
			context()->arr_philos[i - 1].fork_right = \
&context()->arr_philos[i].fork_left;
		if (context()->number_of_philosophers != 1 && i + 1 == \
context()->number_of_philosophers)
			context()->arr_philos[i].fork_right = \
&context()->arr_philos[0].fork_left;
		i++;
	}
}

void	init_context(char **argv)
{
	parse_params(argv);
	context()->stop = 0;
	context()->start_time = get_time() + 500;
	context()->arr_philos = malloc(sizeof(t_philo) * \
context()->number_of_philosophers);
	if (!context()->arr_philos)
		return ((void)(catch()->set("%s: Malloc failure!", __func__)));
	init_philos();
	if (pthread_mutex_init(&context()->stop_lock, NULL) != 0)
		return ((void)(catch()->set("%s: Mutex init error!", __func__)));
	if (pthread_mutex_init(&context()->print_lock, NULL) != 0)
		return ((void)(catch()->set("%s: Mutex init error!", __func__)));
}
