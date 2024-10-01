/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:55:34 by rafasant          #+#    #+#             */
/*   Updated: 2024/09/30 09:56:18 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker.h"

void	parse_move(t_group *group, char *move)
{
	if (!ft_strncmp(move, "sa", 2) && group->size_a >= 2)
		return (swap(&group->a, "sa", 1));
	else if (!ft_strncmp(move, "ra", 2) && group->size_a >= 2)
		return (rotate(&group->a, "ra", 1));
	else if (!ft_strncmp(move, "rra", 3) && group->size_a >= 2)
		return (rev_rotate(&group->a, "rra", 1));
	else if (!ft_strncmp(move, "pb", 2) && group->size_a > 0)
		return (push(&group->b, &group->a, "pb", group, 1));
	else if (!ft_strncmp(move, "sb", 2) && group->size_b >= 2)
		return (swap(&group->b, "sb", 1));
	else if (!ft_strncmp(move, "rb", 2) && group->size_b >= 2)
		return (rotate(&group->b, "rb", 1));
	else if (!ft_strncmp(move, "rrb", 2) && group->size_b >= 2)
		return (rev_rotate(&group->b, "rrb", 1));
	else if (!ft_strncmp(move, "pa", 2) && group->size_b > 0)
		return (push(&group->a, &group->b, "pa", group, 1));
	else if (!ft_strncmp(move, "ss", 2) && group->size_a >= 2 && group->size_b >= 2)
	{
		swap(&group->a, "sa", 1);
		return (swap(&group->b, "sb", 1));
	}
	else if (!ft_strncmp(move, "rr", 2) && group->size_a >= 2 && group->size_b >= 2)
	{
		rotate(&group->b, "ra", 1);
		return (rotate(&group->b, "rb", 1));
	}
	else if (!ft_strncmp(move, "rrr", 2) && group->size_a >= 2 && group->size_b >= 2)
	{
		rotate(&group->b, "rra", 1);
		return (rotate(&group->b, "rrb", 1));
	}
	//deallocate(group, 1);
}

int	main(int argc, char **argv)
{
	t_group		*group;
	t_stack		*temp;
	char		*move;

	if (argc < 2)
		return (0);
	group = init_group(argv);
	move = NULL;
	while (1)
	{
		if (move)
			free(move);
		move = get_next_line(1);
		if (*move == '\n')
			break ;
		parse_move(group, move);
	}
	temp = group->a;
	while (temp != NULL)
	{
		printf("a: %d\n", temp->x);
		temp = temp->next;
	}
	if (list_sorted(group->a) && group->size_b == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	deallocate(group, 2);
	return (0);
}