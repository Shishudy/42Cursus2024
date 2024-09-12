/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:01:34 by rafasant          #+#    #+#             */
/*   Updated: 2024/09/11 22:28:25 by rafasant         ###   ########.fr       */
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
	group->moves = NULL;
	return (group);
}

int main(int argc, char **argv)
{
	t_group		*group;
	t_stack		*temp;
	int			i;

	if (argc < 2)
		return (0);
	group = init_group(argv);
	i = 0;
	void_sort_list_2(group, 0, "sa");
	print_moves(group->array_moves, 4);
	temp = group->a;
	while (temp != NULL)
	{
		i++;
		printf("a: %d\n", temp->x);
		temp = temp->next;
	}
	temp = group->b;
	while (temp != NULL)
	{
		i++;
		printf("b: %d\n", temp->x);
		temp = temp->next;
	}
	return 0;
}