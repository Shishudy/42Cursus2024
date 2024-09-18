/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:32:39 by rafasant          #+#    #+#             */
/*   Updated: 2024/09/18 20:29:44 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_group *group)
{
	if (group->size_a == 2)
		swap(&group->a, "sa");
	else if (group->a->x > group->a->next->x && group->a->next->x > \
	group->a->next->next->x)
	{
		swap(&group->a, "sa");
		rev_rotate(&group->a, "rra");
	}
	else if (group->a->x < group->a->next->x && group->a->x > \
	group->a->next->next->x)
		rev_rotate(&group->a, "rra");
	else if (group->a->x < group->a->next->x && group->a->next->next->x < \
	group->a->next->x)
	{
		swap(&group->a, "sa");
		rotate(&group->a, "ra");
	}
	else if (group->a->x > group->a->next->x && group->a->next->next->x > \
	group->a->x)
		swap(&group->a, "sa");
	else if (group->a->x > group->a->next->x && group->a->x > \
	group->a->next->next->x)
		rotate(&group->a, "ra");
}

int	calculate_cost(t_stack *stack, int stack_size, int target)
{
	t_stack *temp;
	int		moves;

	temp = stack;
	moves = 0;
	while (temp != NULL && temp->x != target)
	{
		moves++;
		temp = temp->next;
	}
	if (stack_size - moves < moves)
		return (-(stack_size - moves));
	return (moves);
}

void	push_cheapest(t_group *group, int cost)
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
}

void	push_back_a(t_group *group)
{
	push(&group->a, &group->b, "pa", group);
	if (group->a->x > group->a->next->x)
		swap(&group->a, "sa");
	push(&group->a, &group->b, "pa", group);
	if (group->a->x > group->a->next->x)
		swap(&group->a, "sa");
}

void	sort_5(t_group *group)
{
	t_stack	*temp;
	int		small;
	int		smallest;

	temp = group->a;
	small = temp->x;
	smallest = temp->x;
	while (temp != NULL)
	{
		if (temp->x < smallest)
		{
			small = smallest;
			smallest = temp->x;
		}
		temp = temp->next;
	}
	push_cheapest(group, calculate_cost(group->a, group->size_a, smallest));
	push_cheapest(group, calculate_cost(group->a, group->size_a, small));
	sort_3(group);
	push_back_a(group);
	add_to_buffer("");
}