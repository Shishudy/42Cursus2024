/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:01:34 by rafasant          #+#    #+#             */
/*   Updated: 2024/09/23 15:55:39 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_group		*group;
	t_stack		*temp;

	if (argc < 2)
		return (0);
	(void)argv;
	group = init_group(argv);
	// sort_biggest(group);
	// push(&group->b, &group->a, "pb", group);
	// add_to_buffer("");
	// printf("size_a: %d\n", group->size_a);
	// printf("size_b: %d\n", group->size_b);
	if (group->size_a <= 3)
		sort_3(group);
	else if (group->size_a <= 5)
		sort_5(group);
	else if (group->size_a < 10)
		sort_less_10(group);
	else
		sort_to_b(group);
	add_to_buffer("");
	temp = group->a;
	while (temp != NULL)
	{
		printf("a: %d\n", temp->x);
		temp = temp->next;
	}
	// temp = group->b;
	// while (temp != NULL)
	// {
	// 	printf("b: %d\n", temp->x);
	// 	temp = temp->next;
	// }
	//printf("size_a: %d\n", group->size_a);
	deallocate(group, 2);
	return 0;
}