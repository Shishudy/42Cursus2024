/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:55:34 by rafasant          #+#    #+#             */
/*   Updated: 2024/10/08 17:35:29 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker.h"

void	parse_move_combo(t_group *group, char *move)
{
	if (!ft_strncmp(move, "ss\n", 3) && group->size_a >= 2 \
	&& group->size_b >= 2)
	{
		swap(&group->a);
		return (swap(&group->b));
	}
	else if (!ft_strncmp(move, "rr\n", 3) && group->size_a >= 2 \
	&& group->size_b >= 2)
	{
		rotate(&group->a);
		return (rotate(&group->b));
	}
	else if (!ft_strncmp(move, "rrr\n", 4) && group->size_a >= 2 \
	&& group->size_b >= 2)
	{
		rev_rotate(&group->a);
		return (rev_rotate(&group->b));
	}
	deallocate(group, 2);
}

void	parse_move(t_group *group, char *move)
{
	if (!ft_strncmp(move, "sa\n", 3) && group->size_a >= 2)
		return (swap(&group->a));
	else if (!ft_strncmp(move, "ra\n", 3) && group->size_a >= 2)
		return (rotate(&group->a));
	else if (!ft_strncmp(move, "rra\n", 4) && group->size_a >= 2)
		return (rev_rotate(&group->a));
	else if (!ft_strncmp(move, "pb\n", 3) && group->size_a > 0)
		return (push(&group->b, &group->a, "pb", group));
	else if (!ft_strncmp(move, "sb\n", 3) && group->size_b >= 2)
		return (swap(&group->b));
	else if (!ft_strncmp(move, "rb\n", 3) && group->size_b >= 2)
		return (rotate(&group->b));
	else if (!ft_strncmp(move, "rrb\n", 4) && group->size_b >= 2)
		return (rev_rotate(&group->b));
	else if (!ft_strncmp(move, "pa\n", 3) && group->size_b > 0)
		return (push(&group->a, &group->b, "pa", group));
	else
		parse_move_combo(group, move);
}

int	main(int argc, char **argv)
{
	t_group	*group;
	char	*move;

	if (argc < 2)
		return (0);
	group = init_group(argv);
	move = NULL;
	while (1)
	{
		if (move)
			free(move);
		move = get_next_line(0);
		if (!move)
			break ;
		parse_move(group, move);
	}
	if (list_sorted(group->a) && group->size_b == 0)
		return (deallocate(group, 0), 0);
	return (deallocate(group, 1), 1);
}
