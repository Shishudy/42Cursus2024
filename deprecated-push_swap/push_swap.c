/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:01:34 by rafasant          #+#    #+#             */
/*   Updated: 2024/07/07 13:08:58 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	(void)argc;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	check_argv(argv, &a);
	b = NULL;
	push(&b, &a, "pa\n");
	push(&a, &b, "pb\n");
	swap(&a, NULL, "sa\n");
	//swap(&b, NULL, "sb\n");
	rotate(&a, NULL, "ra\n");
	rotate(&b, NULL, "rb\n");
	rev_rotate(&a, NULL, "rra\n");
	rev_rotate(&b, NULL, "rrb\n");
	//swap(&a, &b, "ss\n");
	rotate(&a, &b, "rr\n");
	rev_rotate(&a, &b, "rrr\n");
	//sort_list(&a, &b);
	b = a;
	while (a != NULL)
	{
		printf("list: %d\n", a->x);
		a = a->next;
	}
	deallocate(&b, 2);
	return (0);
}