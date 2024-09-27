/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:55:34 by rafasant          #+#    #+#             */
/*   Updated: 2024/09/27 10:05:56 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker.h"

void	parse_move(t_group *group, char *move)
{
	if (ft_strncmp(move, "sa", 2))
		swap(&group->a, "sa");
	else if (ft_strncmp(move, "ra", 2))
		rotate(&group->a, "ra");
	else if (ft_strncmp(move, "rra", 3))
		rev_rotate(&group->a, "rra");
	else if (ft_strncmp(move, "sb", 2))
		swap(&group->b, "sb");
	else if (ft_strncmp(move, "rb", 2))
		rotate(&group->b, "rb");
	else if (ft_strncmp(move, "rrb", 2))
		rev_rotate(&group->b, "rrb");

}

int	main(int argc, char **argv)
{
	t_group		*group;
	char		*move;

	if (argc < 2)
		return (0);
	group = init_group(argv);
	while (1)
	{
		move = get_next_line(1);
		parse_move(group, move);
		if (get_next_line(1) == 0)
		{
			break ;
		}
	}
	if (list_sorted(group->a) && group->size_b == 0)
		write(1, "OK\n", 3);
	else
		deallocate(group, 1);
	return (0);
}