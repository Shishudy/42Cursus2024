/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 11:46:30 by rafasant          #+#    #+#             */
/*   Updated: 2024/07/19 16:10:29 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// push(&b, &a, "pa\n");
// push(&a, &b, "pb\n");
// swap(&a, NULL, "sa\n");
// swap(&b, NULL, "sb\n");
// rotate(&a, NULL, "ra\n");
// rotate(&b, NULL, "rb\n");
// rev_rotate(&a, NULL, "rra\n");
// rev_rotate(&b, NULL, "rrb\n");
// swap(&a, &b, "ss\n");
// rotate(&a, &b, "rr\n");
// rev_rotate(&a, &b, "rrr\n");

void	push(t_stack **send_to, t_stack **send_from, char *move)
{
	t_stack	*temp;

	temp = *send_from;
	*send_from = temp->next;
	temp->next = *send_to;
	*send_to = temp;
	write(1, move, ft_strlen(move));
}

void	swap(t_stack **list1, t_stack **list2, char *move)
{
	int	value;

	value = (*list1)->x;
	(*list1)->x = (*list1)->next->x;
	(*list1)->next->x = value;
	if (list2 && !ft_strncmp(move, "ss", 2))
	{
		value = (*list2)->x;
		(*list2)->x = (*list2)->next->x;
		(*list2)->next->x = value;
	}
	write(1, move, ft_strlen(move));
}

void	rotate(t_stack **list1, t_stack **list2, char *move)
{
	// t_stack	*temp;

	// temp = *list1;
	// *list1 = (*list1)->next;

	// if (list2 && !ft_strncmp(move, "rr", 2))
	// {

	// }
	t_stack	*curr;
	t_stack	*temp;

	curr = *list1;
	temp = *list1;
	*list1 = curr->next;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = temp;
	temp->next = NULL;
	write(1, move, ft_strlen(move));
}

void	rev_rotate(t_stack **list1, t_stack **list2, char *move)
{
	if (list2 && !ft_strncmp(move, "rrr", 3))
	{
	}
	write(1, move, ft_strlen(move));
}
