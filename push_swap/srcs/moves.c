/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 11:46:30 by rafasant          #+#    #+#             */
/*   Updated: 2024/09/30 09:44:20 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

// push(&b, &a, "pa\n");
// push(&a, &b, "pb\n");
// swap(&a, "sa\n");
// swap(&b, "sb\n");
// rotate(&a, "ra\n");
// rotate(&b, "rb\n");
// rev_rotate(&a, "rra\n");
// rev_rotate(&b, "rrb\n");

void	add_to_buffer(char *move, int flag)
{
	static char	*buffer;

	if (flag == 1)
		return ;
	if (buffer)
	{
		if (ft_strlen(move) == ft_strlen(buffer) && !ft_strncmp(buffer, \
		move, 1) && (ft_strncmp(buffer, move, 3) == 1 || \
		ft_strncmp(buffer, move, 3) == -1) && (buffer[0] != 'p' && \
		move[0] != 'p'))
		{
			write(1, buffer, ft_strlen(buffer) - 1);
			write(1, buffer, 1);
			write(1, "\n", 1);
			buffer = NULL;
			return ;
		}
		else
		{
			write(1, buffer, ft_strlen(buffer));
			write(1, "\n", 1);
		}
	}
	buffer = move;
}

void	push(t_stack **send_to, t_stack **send_from, char *move, t_group *group, int flag)
{
	t_stack	*temp;

	temp = *send_from;
	*send_from = temp->next;
	temp->next = *send_to;
	*send_to = temp;
	add_to_buffer(move, flag);
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
	// write(1, move, ft_strlen(move));
	// write(1, "\n", 1);
}

void	swap(t_stack **stack, char *move, int flag)
{
	int	value;

	value = (*stack)->x;
	(*stack)->x = (*stack)->next->x;
	(*stack)->next->x = value;
	add_to_buffer(move, flag);
	// write(1, move, ft_strlen(move));
	// write(1, "\n", 1);
}

void	rotate(t_stack **stack, char *move, int flag)
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
	add_to_buffer(move, flag);
	// write(1, move, ft_strlen(move));
	// write(1, "\n", 1);
}

void	rev_rotate(t_stack **stack, char *move, int flag)
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
	add_to_buffer(move, flag);
	// write(1, move, ft_strlen(move));
	// write(1, "\n", 1);
}