/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:34:33 by rafasant          #+#    #+#             */
/*   Updated: 2024/10/03 19:22:36 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	cnt_rec(t_stack *stack, int min, int max, int value)
{
	if (stack == NULL)
		return (value);
	if (stack->x <= max && stack->x >= min)
		value = stack->x;
	return (cnt_rec(stack->next, min, max, value));
}

void	start_chunk(t_group *group)
{
	t_stack	*temp;
	t_stack	*clone;

	clone = clone_list(group->a);
	sort_list(clone);
	temp = clone;
	group->chunk->start = temp->x;
	ft_free_stack(&clone);
}

void	end_chunk(t_group *group)
{
	t_stack	*temp;
	t_stack	*clone;

	clone = clone_list(group->a);
	sort_list(clone);
	temp = clone;
	group->chunk->end = 1;
	while (temp->next != NULL && group->chunk->end != group->chunk->chunk_size)
	{
		group->chunk->end++;
		temp = temp->next;
	}
	group->chunk->end = temp->x;
	ft_free_stack(&clone);
}

void	midpoint(t_group *group, t_stack *stack, int start, int end)
{
	t_stack	*temp;
	t_stack	*clone;
	int		size;

	clone = clone_list(stack);
	sort_list(clone);
	temp = clone;
	size = 0;
	while (temp != NULL && temp->x != start)
		temp = temp->next;
	while (temp != NULL && temp->x != end)
	{
		size++;
		temp = temp->next;
	}
	group->chunk->midpoint = size / 2;
	temp = clone;
	while (temp != NULL && temp->x != start)
		temp = temp->next;
	while (group->chunk->midpoint-- > 0 && temp->next != NULL)
		temp = temp->next;
	group->chunk->midpoint = temp->x;
	ft_free_stack(&clone);
}
