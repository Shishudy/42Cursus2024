/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 18:08:13 by rafasant          #+#    #+#             */
/*   Updated: 2025/08/17 19:08:50 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	clear_context()
{
	if (pthread_mutex_destroy(&context()->stop_lock))
		return ((void) (catch()->set("%s: Mutex destruction failure!", __func__)));
	if (pthread_mutex_destroy(&context()->print_lock))
		return ((void) (catch()->set("%s: Mutex destruction failure!", __func__)));
	free(context()->arr_philos);
}

void	clear_philos()
{
	int	i;

	i = 0;
	while (i < context()->number_of_philosophers)
	{
		if (pthread_mutex_destroy(&context()->arr_philos[i].fork_left))
			return ((void) (catch()->set("%s: Mutex destruction failure!", __func__)));
		if (pthread_mutex_destroy(&context()->arr_philos[i].meal_lock))
			return ((void) (catch()->set("%s: Mutex destruction failure!", __func__)));
		i++;
	}
}