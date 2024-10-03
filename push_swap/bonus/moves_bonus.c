/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 11:46:30 by rafasant          #+#    #+#             */
/*   Updated: 2024/10/03 16:31:35 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker.h"

void	push(t_stack **send_to, t_stack **send_from, char *move, t_group *group)
{
	t_stack	*temp;

	temp = *send_from;
	*send_from = temp->next;
	temp->next = *send_to;
	*send_to = temp;
	if (!ft_strncmp("pa", move, 2))
	{
		group->size_a++;
		group->size_b--;
	}
	else if (!ft_strncmp("pb", move, 2))
	{
		group->size_a--;
		group->size_b++;
	}
}

void	swap(t_stack **stack)
{
	int	value;

	value = (*stack)->x;
	(*stack)->x = (*stack)->next->x;
	(*stack)->next->x = value;
}

void	rotate(t_stack **stack)
{
	t_stack	*curr;
	t_stack	*temp;

	curr = *stack;
	temp = *stack;
	*stack = curr->next;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = temp;
	temp->next = NULL;
}

void	rev_rotate(t_stack **stack)
{
	t_stack	*curr;
	t_stack	*temp;

	curr = *stack;
	temp = *stack;
	if (curr && curr->next)
	{
		while (curr->next != NULL)
			curr = curr->next;
		if (temp && temp->next && temp->next->next)
		{
			while (temp->next->next != NULL)
				temp = temp->next;
		}
		curr->next = *stack;
		*stack = curr;
		temp->next = NULL;
	}
}
