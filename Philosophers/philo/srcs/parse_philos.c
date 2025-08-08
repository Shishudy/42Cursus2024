/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_philos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:42:08 by rafasant          #+#    #+#             */
/*   Updated: 2025/08/08 16:12:43 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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

void	parse_philos(char **argv)
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
				return ((void)\
(catch()->set_error("%s: Invalid number!", __func__)));
			j++;
		}
		assign_value(n, i);
		i++;
	}
	if (context()->number_of_philosophers < 1)
		return ((void)\
(catch()->set_error("%s: Invalid number of philos", __func__)));
}