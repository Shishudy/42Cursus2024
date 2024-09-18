/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:01:34 by rafasant          #+#    #+#             */
/*   Updated: 2024/09/18 20:28:58 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_calculator(t_group *group)
{
	if (group->size_a == 100)
		group->chunk->chunk_size = 12;
	else if (group->size_a == 500)
		group->chunk->chunk_size = 35;
	else
		group->chunk->chunk_size = group->size_a / 10;
	//intervalo de valores dentro da chunk
}

t_group	*init_group(char **argv)
{
	t_group	*group;

	group = malloc(sizeof(t_group));
	if (!group)
		exit(write(2, "Error\n", 6));
	group->chunk = malloc(sizeof(t_chunk));
	if (!group->chunk)
		exit(write(2, "Error\n", 6));
	group->bf = malloc(sizeof(t_bf));
	if (!group->bf)
		exit(write(2, "Error\n", 6));
	group->a = NULL;
	group->b = NULL;
	check_argv(group, argv);
	if (!group->a)
		exit(write(2, "Error\n", 6));
	group->size_a = ft_stack_size(group->a);
	group->size_b = 0;
	chunk_calculator(group);
	group->bf->end_chunk = 0;
	group->bf->index_a = 0;
	group->bf->cost = 0;
	return (group);
}

int main(int argc, char **argv)
{
	t_group		*group;
	//t_stack		*temp;

	if (argc < 2)
		return (0);
	(void)argv;
	group = init_group(argv);
	//sort_biggest(group);
	// push(&group->b, &group->a, "pb", group);
	// add_to_buffer("");
	// printf("size_a: %d\n", group->size_a);
	// printf("size_b: %d\n", group->size_b);
	if (group->size_a <= 3)
		sort_3(group);
	if (group->size_a <= 5)
		sort_5(group);
	// temp = group->a;
	// while (temp != NULL)
	// {
	// 	printf("a: %d\n", temp->x);
	// 	temp = temp->next;
	// }
	// temp = group->b;
	// while (temp != NULL)
	// {
	// 	printf("b: %d\n", temp->x);
	// 	temp = temp->next;
	// }
	deallocate(group, 2);
	return 0;
}