/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:03:01 by rafasant          #+#    #+#             */
/*   Updated: 2025/08/06 17:39:31 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (write(2, "Wrong number of arguments!\n", 28));
	check_params(argv);
	if (catch()->error_msg != NULL)
		return (printf("%s\n", catch()->error_msg), 1);
	parse_philos(argv);
	if (catch()->error_msg != NULL)
		return (printf("%s\n", catch()->error_msg), 1);
	start_philos();
	if (catch()->error_msg != NULL)
		return (printf("%s\n", catch()->error_msg), 1);
	return (0);
}