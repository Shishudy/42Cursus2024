/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:34:33 by rafasant          #+#    #+#             */
/*   Updated: 2024/10/02 18:36:20 by rafasant         ###   ########.fr       */
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

int	find_cheapest(t_stack *stack, int min, int max, int size)
{
	t_stack	*temp;
	int	cost_top;
	int	cost_bot;

	temp = stack;
	while (temp != NULL && (temp->x < min || temp->x > max))
		temp = temp->next;
	cost_top = calculate_cost(stack, size, temp->x, 1);
	cost_bot = calculate_cost(stack, size, cnt_rec(stack, min, max, stack->x), -1);
	if (-cost_bot < cost_top)
		cost_top = cost_bot;
	return (cost_top);
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
	group->chunk->end = 0;
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
	while (group->chunk->midpoint > 0 && temp->next != NULL)
	{
		temp = temp->next;
		group->chunk->midpoint--;
	}
	group->chunk->midpoint = temp->x;
	ft_free_stack(&clone);
}