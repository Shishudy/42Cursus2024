/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:03:01 by rafasant          #+#    #+#             */
/*   Updated: 2025/05/23 18:24:36 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*func(void){}

int	main(int argc, char **argv)
{
	if (argc < 4 || argc > 5)
		return (write(2, "Wrong number of arguments!\n", 28));
	check_params(argv);
	if (catch()->error_msg)
		return (printf("%s\n", catch()->error_msg), 1);
	parse_philos(argv);
	if (catch()->error_msg)
		return (printf("%s\n", catch()->error_msg), 1);
	philos()->arr_philos = malloc(sizeof(pthread_t) * philos()->number_of_philosophers + 1);
	if (philos()->arr_philos)
		return (catch()->error_msg = "Malloc failure!", 1);
	philos()->arr_philos[philos()->number_of_philosophers] = NULL;
	int	i;
	i = 0;
	while (i < philos()->number_of_philosophers)
	{
		if (pthread_create(philos()->arr_philos[i], NULL, &func, NULL) != 0)
		{
			return (catch()->error_msg = "Thread creation failure!", 1);
		}
	}
}