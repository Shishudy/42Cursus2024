/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 11:46:30 by rafasant          #+#    #+#             */
/*   Updated: 2024/08/17 13:35:30 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// push(&b, &a, "pa\n");
// push(&a, &b, "pb\n");
// swap(&a, "sa\n");
// swap(&b, "sb\n");
// rotate(&a, "ra\n");
// rotate(&b, "rb\n");
// rev_rotate(&a, "rra\n");
// rev_rotate(&b, "rrb\n");

void	push(t_stack **send_to, t_stack **send_from, char *move)
{
	t_stack	*temp;

	temp = *send_from;
	*send_from = temp->next;
	temp->next = *send_to;
	*send_to = temp;
	// write(1, move, ft_strlen(move));
	// write(1, "\n", 1);
}

void	swap(t_stack **stack, char *move)
{
	int	value;

	value = (*stack)->x;
	(*stack)->x = (*stack)->next->x;
	(*stack)->next->x = value;
	// write(1, move, ft_strlen(move));
	// write(1, "\n", 1);
}

void	rotate(t_stack **stack, char *move)
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
	// write(1, move, ft_strlen(move));
	// write(1, "\n", 1);
}

void	rev_rotate(t_stack **stack, char *move)
{
	t_stack	*curr;
	t_stack	*temp;

	curr = *stack;
	temp = *stack;
	while (curr->next != NULL)
		curr = curr->next;
	while (temp->next->next != NULL)
		temp = temp->next;
	curr->next = *stack;
	*stack = curr;
	temp->next = NULL;
	// write(1, move, ft_strlen(move));
	// write(1, "\n", 1);
}
