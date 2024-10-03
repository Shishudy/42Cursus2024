/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:33:12 by rafasant          #+#    #+#             */
/*   Updated: 2024/10/03 18:47:48 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

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
