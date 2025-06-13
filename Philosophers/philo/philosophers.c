/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:03:01 by rafasant          #+#    #+#             */
/*   Updated: 2025/06/13 17:11:38 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	struct timeval	tv;

	if (argc < 5 || argc > 6)
		return (write(2, "Wrong number of arguments!\n", 28));
	check_params(argv);
	if (catch()->error_msg != NULL)
		return (printf("%s\n", catch()->error_msg), 1);
	parse_philos(argv);
	if (catch()->error_msg != NULL)
		return (printf("%s\n", catch()->error_msg), 1);
	gettimeofday(&tv, NULL);
	philos()->start_time = tv.tv_sec;
	start_philos();
	if (catch()->error_msg != NULL)
		return (printf("%s\n", catch()->error_msg), 1);
}