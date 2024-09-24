/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:50:55 by rafasant          #+#    #+#             */
/*   Updated: 2024/09/24 00:53:38 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_rest_b(t_group *group)
{
	t_stack	*temp;
	t_stack	*clone;
	int		i;
	int		temp_chunk;

	group->chunk->chunk_size = group->chunk->chunk_size / 2;
	start_chunk(group);
	end_chunk(group);
	midpoint(group, group->a, group->chunk->start, group->chunk->end);
	temp_chunk = group->chunk->chunk_size;
	while (temp_chunk >= 0)
	{
		push_cheapest_a(group, find_cheapest(group->a, group->chunk->start, group->chunk->end, group->size_a));
		if (group->b->x < group->chunk->midpoint && group->size_b >= 2)
			rotate(&group->b, "rb");
		temp_chunk--;
	}
	clone = clone_list(group->a);
	sort_list(clone);
	temp = clone;
	group->chunk->start = temp->x;
	i = 0;
	while (group->size_a - i > 10 && temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	group->chunk->end = temp->x;
	ft_free_stack(&clone);
	group->chunk->chunk_size = group->chunk->chunk_size - 10;
	end_chunk(group);
	midpoint(group, group->a, group->chunk->start, group->chunk->end);
	while (group->size_a >= 10)
	{
		push_cheapest_a(group, find_cheapest(group->a, group->chunk->start, group->chunk->end, group->size_a));
		if (group->b->x < group->chunk->midpoint && group->size_b >= 2)
			rotate(&group->b, "rb");
	}
}

void	sort_to_b(t_group *group)
{
	t_stack	*temp;
	int		temp_chunk;
	int		chunks;

	temp = group->a;
	chunks = (group->chunk->chunks - 2) / 2;
	while (chunks--)
	{
		start_chunk(group);
		end_chunk(group);
		midpoint(group, group->a, group->chunk->start, group->chunk->end);
		temp_chunk = group->chunk->chunk_size;
		while (temp_chunk >= 0)
		{
			push_cheapest_a(group, find_cheapest(group->a, group->chunk->start, group->chunk->end, group->size_a));
			if (group->b->x < group->chunk->midpoint && group->size_b >= 2)
				rotate(&group->b, "rb");
			temp_chunk--;
		}
	}
	push_rest_b(group);
	// sort_less_10(group);
	//sort_rest_a(group);
	// sort_5(group);
	// printf("%d\n", group->chunk->start);
	// printf("%d\n", group->chunk->end);
}

// void	sort_biggest(t_group *group)
// {
// 	while (group->size_a != 0)
// 		best_move(group);
// 	// add_to_buffer("");
// 	// sort_back_a(group);
// 	// chunk_midpoint(group);
// }