/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:01:34 by rafasant          #+#    #+#             */
/*   Updated: 2024/09/13 20:51:04 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_group	*init_group(char **argv)
{
	t_group	*group;

	group = malloc(sizeof(t_group));
	if (!group)
		exit(write(2, "Error\n", 6));
	group->a = NULL;
	group->b = NULL;
	check_argv(argv, &group->a);
	if (!group->a)
		exit(write(2, "Error\n", 6));
	return (group);
}

int main(int argc, char **argv)
{
	t_group		*group;
	t_stack		*temp;

	if (argc < 2)
		return (0);
	group = init_group(argv);
	push(&group->b, &group->a, "pb");
	push(&group->b, &group->a, "pb");
	swap(&group->b, "sb");
	swap(&group->a, "sa");
	rotate(&group->b, "rb");
	rev_rotate(&group->b, "rrb");
	rotate(&group->a, "ra");
	rev_rotate(&group->a, "rra");
	add_to_buffer("");
	temp = group->a;
	while (temp != NULL)
	{
		printf("a: %d\n", temp->x);
		temp = temp->next;
	}
	temp = group->b;
	while (temp != NULL)
	{
		printf("b: %d\n", temp->x);
		temp = temp->next;
	}
	deallocate(group, 2);
	return 0;
}