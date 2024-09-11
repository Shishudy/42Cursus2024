/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:52:54 by rafasant          #+#    #+#             */
/*   Updated: 2024/07/29 15:45:42 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_size(t_stack *lst)
{
	int	size;

	size = 0;
	while (lst != NULL)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

// int	compare_lists(t_stack **og, t_stack **clone)
// {
// 	while (og && clone)
// 	{
// 		if (og->x != clone->x)
// 			return (-1);
// 	}
// }

// t_stack	*ft_lstclone(t_stack *lst)
// {
// 	t_stack	*new_lst;

// 	new_lst = NULL;
// 	while (lst != NULL)
// 	{
// 		ft_addtolist(&new_lst, lst->x);
// 		lst = lst->next;
// 	}
// 	if (compare_lists(lst, new_lst) == -1)
// 		return (NULL);
// 	return (new_lst);
// }

// void (*p[4]) (t_stack **a, t_stack **b, char *move);

// void	prepare_sort_list(t_stack **a, t_stack **b)
// {
// 	int		moves;
// 	t_stack	*clone_a;
// 	t_stack	*clone_b;
	
// 	p[0] = push;
// 	p[1] = swap;
// 	p[2] = rotate;
// 	p[3] = rev_rotate;
// 	moves = 0;
// 	while (moves != -1 && moves < 5500)
// 	{
// 		clone_a = ft_lstclone(a);
// 		if (clone_a == NULL)
// 			deallocate(a, 1);
// 		clone_b = NULL;
// 		moves = sort_list(clone_a, clone_b, 0, NULL);
// 	}
// 	sort_list(clone_a, clone_b, 0, push);
// }

// void	put_move_array(char **array_moves, char *move)
// {
// 	int	i;

// 	i = 0;
// 	while (move)
// 	{
// 		array_moves[moves][i] = move[i];
// 		i++;
// 	}
// }

// int	sort_list(t_stack **clone_a, t_stack **clone_b, int moves, void (f)(t_stack **clone_a, t_stack **clone_b, char *move), char *move)
// {
// 	int	op;
// 	static char	**array_moves[5500][4];

// 	if (list_sorted(clone_a) && !clone_b)
// 		return (moves);
// 	if (moves >= 5500)
// 		return (moves - 1);
// 	op = 0;
// 	f(clone_a, clone_b, move);
// 	put_move_array(&array_moves, moves, move);
// 	moves = sort_list(clone_b, clone_a, moves + 1, push, "pb\n");
// 	moves = sort_list(clone_b, clone_a, moves + 1, swap, "sb\n");
// 	moves = sort_list(clone_b, clone_a, moves + 1, rotate, "rb\n");
// 	moves = sort_list(clone_b, clone_a, moves + 1, rev_rotate, "rrb\n");
// 	moves = sort_list(clone_a, clone_b, moves + 1, push, "pa\n");
// 	moves = sort_list(clone_a, clone_b, moves + 1, swap, "sa\n");
// 	moves = sort_list(clone_a, clone_b, moves + 1, rotate, "ra\n");
// 	moves = sort_list(clone_a, clone_b, moves + 1, rev_rotate, "rra\n");
// 	if (!list_sorted(clone_a) || clone_b || moves == 5500)
// 		return (moves - 1);
// }
