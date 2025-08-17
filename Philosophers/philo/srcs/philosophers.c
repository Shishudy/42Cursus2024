/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:03:01 by rafasant          #+#    #+#             */
/*   Updated: 2025/08/17 14:49:09 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (write(2, "Wrong number of arguments!\n", 28));
	check_params(argv);
	if (catch()->error_msg != NULL)
		return (catch()->print(), catch()->free(), 1);
	init_context(argv);
	if (catch()->error_msg != NULL)
		return (catch()->print(), catch()->free(), 1);
	print_context(context());
	run_simulation();
	if (catch()->error_msg != NULL)
		return (catch()->print(), catch()->free(), 1);
	return (0);
}