/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:34:46 by rafasant          #+#    #+#             */
/*   Updated: 2024/10/03 20:12:33 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	push_cheapest_a(t_group *group, int cost)
{
	while (cost != 0)
	{
		if (cost < 0)
		{
			rev_rotate(&group->a, "rra");
			cost++;
		}
		else if (cost > 0)
		{
			rotate(&group->a, "ra");
			cost--;
		}
	}
	push(&group->b, &group->a, "pb", group);
	if (group->b->x < group->chunk->midpoint && group->size_b >= 2)
		rotate(&group->b, "rb");
	group->control++;
}

void	push_cheapest_b(t_group *group, int cost)
{
	while (cost != 0)
	{
		if (cost < 0)
		{
			rev_rotate(&group->b, "rrb");
			cost++;
		}
		else if (cost > 0)
		{
			rotate(&group->b, "rb");
			cost--;
		}
	}
	push(&group->a, &group->b, "pa", group);
	if (group->a->x > group->a->next->x)
		swap(&group->a, "sa");
	group->control--;
}

int	calculate_cost(t_stack *stack, int stack_size, int target, int flag)
{
	t_stack	*temp;
	int		moves;

	temp = stack;
	moves = 0;
	while (temp != NULL && temp->x != target)
	{
		moves++;
		temp = temp->next;
	}
	if (flag == -2)
		return (-(stack_size - moves));
	if (stack_size - moves < moves && flag != 2)
		return (-(stack_size - moves));
	return (moves);
}

int	find_cheapest(t_stack *stack, int min, int max, int size)
{
	t_stack	*temp;
	int		cost_top;
	int		cost_bot;

	temp = stack;
	while (temp != NULL && (temp->x < min || temp->x > max))
		temp = temp->next;
	cost_top = calculate_cost(stack, size, temp->x, 2);
	cost_bot = calculate_cost(stack, size, cnt_rec(stack, min, max, \
	stack->x), -2);
	if (-cost_bot < cost_top)
		cost_top = cost_bot;
	return (cost_top);
}

int	find_value(t_stack *stack, int flag)
{
	t_stack	*temp;
	int		value;

	temp = stack;
	value = temp->x;
	while (temp != NULL)
	{
		if (temp->x < value && flag == 1)
			value = temp->x;
		else if (temp->x > value && flag == 2)
			value = temp->x;
		temp = temp->next;
	}
	return (value);
}
