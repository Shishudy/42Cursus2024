/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:50:55 by rafasant          #+#    #+#             */
/*   Updated: 2024/10/02 21:57:21 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	find_biggest_b(t_group *group)
{
	t_stack	*temp;
	t_stack	*clone;

	clone = clone_list(group->b);
	sort_list(clone);
	temp = clone;
	while (temp->next->next->next != NULL)
		temp = temp->next;
	group->chunk->start = temp->x;
	while (temp->next != NULL)
		temp = temp->next;
	group->chunk->end = temp->x;
	ft_free_stack(&clone);
}

void	sort_rest_a(t_group *group)
{
	int	i;

	while (group->size_b > 3)
	{
		i = 0;
		find_biggest_b(group);
		while (i < 3)
		{
			push_cheapest_b(group, find_cheapest(group->b, \
			group->chunk->start, group->chunk->end, group->size_b));
			if (group->a->x > group->a->next->x)
				swap(&group->a, "sa", 0);
			re_sort_3(group);
			i++;
		}
	}
	while (group->size_b > 0)
	{
		push(&group->a, &group->b, "pa", group, 0);
		if (group->a->x > group->a->next->x)
			swap(&group->a, "sa", 0);
		re_sort_3(group);
	}
}

void	push_rest_b(t_group *group)
{
	t_stack	*temp;
	t_stack	*clone;
	int		i;

	if (group->size_a < 10)
		return ;
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
	midpoint(group, group->a, group->chunk->start, group->chunk->end);
	while (group->size_a >= 10)
	{
		push_cheapest_a(group, find_cheapest(group->a, group->chunk->start, \
		group->chunk->end, group->size_a));
		if (group->b->x < group->chunk->midpoint && group->size_b >= 2)
			rotate(&group->b, "rb", 0);
	}
}

void	push_last_chunk(t_group *group)
{
	int		temp_chunk;

	if (group->size_a < 10)
		return ;
	group->chunk->chunk_size = group->chunk->chunk_size / 2;
	start_chunk(group);
	end_chunk(group);
	midpoint(group, group->a, group->chunk->start, group->chunk->end);
	temp_chunk = group->chunk->chunk_size;
	while (temp_chunk > 0)
	{
		push_cheapest_a(group, find_cheapest(group->a, group->chunk->start, \
		group->chunk->end, group->size_a));
		if (group->b->x < group->chunk->midpoint && group->size_b >= 2)
			rotate(&group->b, "rb", 0);
		temp_chunk--;
	}
}

void	sort_to_b(t_group *group)
{
	int		temp_chunk;
	int		chunks;

	chunks = (group->chunk->chunks - 2) / 2;
	while (chunks--)
	{
		start_chunk(group);
		end_chunk(group);
		midpoint(group, group->a, group->chunk->start, group->chunk->end);
		temp_chunk = group->chunk->chunk_size;
		while (temp_chunk > 0)
		{
			push_cheapest_a(group, find_cheapest(group->a, \
			group->chunk->start, group->chunk->end, group->size_a));
			if (group->b->x <= group->chunk->midpoint && group->size_b >= 2)
				rotate(&group->b, "rb", 0);
			temp_chunk--;
		}
	}
	write(1, "group->size_a:", 14);
	ft_putnbr_fd(group->size_a, 1);
	write(1, "\n", 1);
	write(1, "push_last_chunk\n", 16);
	push_last_chunk(group);
	write(1, "push_rest_b\n", 12);
	push_rest_b(group);
	write(1, "sort_less_10\n", 13);
	sort_less_10(group);
	write(1, "sort_rest_a\n", 12);
	sort_rest_a(group);
}
