/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_group.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:36:30 by rafasant          #+#    #+#             */
/*   Updated: 2024/09/27 09:40:53 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	chunk_calculator(t_group *group)
{
	if (group->size_a == 100)
	{
		group->chunk->chunk_size = 24;
		group->chunk->chunks = 8;
	}
	else if (group->size_a == 500)
	{
		group->chunk->chunk_size = 70;
		group->chunk->chunks = 14;
	}
	else if (group->size_a >= 10)
	{
		group->chunk->chunks = 10;
		group->chunk->chunk_size = (group->size_a / group->chunk->chunks) * 2;
	}
	else
		group->chunk->chunk_size = group->size_a;
}

t_group	*init_group(char **argv)
{
	t_group	*group;

	group = malloc(sizeof(t_group));
	if (!group)
		exit(write(2, "Error\n", 6));
	group->chunk = malloc(sizeof(t_chunk));
	if (!group->chunk)
		deallocate(group, 1);
	group->sort = malloc(sizeof(t_sort));
	if (!group->sort)
		deallocate(group, 1);
	group->a = NULL;
	group->b = NULL;
	check_argv(group, argv);
	if (!group->a)
		deallocate(group, 1);
	group->size_a = ft_stack_size(group->a);
	group->size_b = 0;
	chunk_calculator(group);
	group->sort->control = 0;
	group->sort->control2 = 0;
	return (group);
}