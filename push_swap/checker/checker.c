/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:55:34 by rafasant          #+#    #+#             */
/*   Updated: 2024/09/26 20:28:45 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker.h"

int	main(int argc, char **argv)
{
	t_group		*group;

	if (argc < 2)
		return (0);
	group = init_group(argv);
	while(1)
	{
		
	}
	list_sorted(group->a);
}