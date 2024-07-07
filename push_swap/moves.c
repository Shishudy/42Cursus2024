/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 11:46:30 by rafasant          #+#    #+#             */
/*   Updated: 2024/07/07 16:03:15 by rafasant         ###   ########.fr       */
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

	temp = *send_to;
	*send_to = *send_from;
	*send_from = (*send_from)->next;
	(*send_to)->next = temp;
	write(1, move, ft_strlen(move));
}

void	swap(t_stack **list1, t_stack **list2, char *move)
{
	int	value;

	value = (*list1)->x;
	(*list1)->x = (*list1)->next->x;
	(*list1)->next->x = value;
	if (list2)
	{
		value = (*list2)->x;
		(*list2)->x = (*list2)->next->x;
		(*list2)->next->x = value;
	}
	// t_stack	*temp;

	// temp = *list1;
	// *list1 = (*list1)->next;
	// (*list1)->next = temp;
	// if (list2)
	// {
	// 	printf("%p\n", list2);
	// 	temp = *list2;
	// 	*list2 = (*list2)->next;
	// 	(*list2)->next = temp;
	// }
	write(1, move, ft_strlen(move));
}

void	rotate(t_stack **list1, t_stack **list2, char *move)
{
	write(1, move, ft_strlen(move));
}

void	rev_rotate(t_stack **list1, t_stack **list2, char *move)
{
	write(1, move, ft_strlen(move));
}
