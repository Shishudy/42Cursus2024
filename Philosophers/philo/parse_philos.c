/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_philos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:42:08 by rafasant          #+#    #+#             */
/*   Updated: 2025/05/23 15:35:03 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
				return ((void)(catch()->error_msg = "Invalid number!"));
			j++;
		}
		*(&philos()->number_of_philosophers + (i - 1) * 4) = n;
		printf("%d\n", *(&philos()->number_of_philosophers + (i - 1) * 4));
		i++;
	}
	if (philos()->number_of_philosophers < 1)
		return ((void)(catch()->error_msg = "Invalid number of philos!"));
}