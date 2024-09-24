/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:34:46 by rafasant          #+#    #+#             */
/*   Updated: 2024/09/24 00:28:10 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_list(t_stack *root)
{
	t_stack	*current;
	t_stack	*index;
	int		temp;

	if (!root)
		return ;
	temp = 0;
	index = NULL;
	current = root;
	while (current != NULL)
	{
		index = current->next;
		while (index != NULL)
		{
			if (current->x > index->x)
			{
				temp = current->x;
				current->x = index->x;
				index->x = temp;
			}
			index = index->next;
		}
		current = current->next;
	}
}

t_stack	*clone_list(t_stack *root)
{
	t_stack	*new_list;
	t_stack	*new_node;
	t_stack	*prev;
	t_stack	*curr;

	prev = NULL;
	new_list = NULL;
	curr = root;
	while (curr != NULL)
	{
		new_node = malloc(sizeof(t_stack));
		new_node->x = curr->x;
		new_node->next = NULL;
		if (prev != NULL)
			prev->next = new_node;
		else
			new_list = new_node;
		prev = new_node;
		curr = curr->next;
	}
	return (new_list);
}

int	list_sorted(t_stack *stack)
{
	t_stack	*temp;

	if (!stack)
		return (0);
	temp = stack;
	while (temp->next)
	{
		if (temp->x > temp->next->x)
			return (0);
		temp = temp->next;
	}
	return (1);
}

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
	if (flag == -1)
		return (-(stack_size - moves));
	return (moves);
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