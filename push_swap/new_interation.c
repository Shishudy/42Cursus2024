/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_interation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:06:16 by rafasant          #+#    #+#             */
/*   Updated: 2024/08/31 20:36:49 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_stack **stack)
{
	t_stack *temp;

	temp = *stack;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

void	ft_free(t_group **group)
{
	ft_free_stack(&(*group)->a);
	if ((*group)->b)
		ft_free_stack(&(*group)->b);
	if ((*group)->clone_a)
		ft_free_stack(&(*group)->clone_a);
	if ((*group)->clone_b)
		ft_free_stack(&(*group)->clone_b);
	if ((*group)->array_moves)
		free((*group)->array_moves);
	free(*group);
}

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

// should be good
void    put_move_array(char **array_moves, char *move, int n_move)
{
    int i;

	i = 0;
	while (i < 3)
	{
		array_moves[n_move][i] = '\0';
		i++;
	}
    i = 0;
    while (move[i])
    {
        array_moves[n_move][i] = move[i];
        i++;
    }
    array_moves[n_move][i] = '\0';
    printf("move added [%d]: %s\n", n_move, array_moves[n_move]);
}

int	calculate_max_moves(t_stack *a)
{
	float	max_moves;
	int		stack_size;

	stack_size = ft_stack_size(a);
	max_moves = ((0.0000267919918 * stack_size * stack_size * stack_size \
	* stack_size) - (0.0163166992 * stack_size * stack_size * stack_size) \
	+ (1.49465168 * stack_size * stack_size) - (6.16498258 * stack_size) + \
	7.48146338);
	return ((int)max_moves);
}

void	clear_array_moves(char **array_moves)
{
	int	i;

	i = 0;
	while (array_moves[i] != 0)
	{
		free(array_moves[i]);
		i++;
	}
}

void	print_moves(char **array_moves, int n_moves)
{
	int	i;

	i = 0;
	while (array_moves[i] != 0 && i < n_moves)
	{
		if (i + 1 < n_moves)
		{
			if (i + 1 <= n_moves && !ft_strncmp(array_moves[i], "sa", 2) && !ft_strncmp(array_moves[i + 1], "sb", 2))
				i += write(1, "ss", 2) - 1;
			else if (i + 1 <= n_moves && !ft_strncmp(array_moves[i], "sb", 2) && !ft_strncmp(array_moves[i + 1], "sa", 2))
				i += write(1, "ss", 2) - 1;
			else if (i + 1 <= n_moves && !ft_strncmp(array_moves[i], "ra", 2) && !ft_strncmp(array_moves[i + 1], "rb", 2))
				i += write(1, "rr", 2) - 1;
			else if (i + 1 <= n_moves && !ft_strncmp(array_moves[i], "rb", 2) && !ft_strncmp(array_moves[i + 1], "ra", 2))
				i += write(1, "rr", 2) - 1;
			else if (i + 1 <= n_moves && !ft_strncmp(array_moves[i], "rra", 3) && !ft_strncmp(array_moves[i + 1], "rrb", 3))
				i += write(1, "rrr", 3) - 2;
			else if (i + 1 <= n_moves && !ft_strncmp(array_moves[i], "rrb", 3) && !ft_strncmp(array_moves[i + 1], "rra", 3))
				i += write(1, "rrr", 3) - 2;
			else
				write(1, array_moves[i], ft_strlen(array_moves[i]));
		}
		else
			write(1, array_moves[i], ft_strlen(array_moves[i]));
		write(1, "\n", 1);
		i++;
	}
	clear_array_moves(array_moves);
}

t_stack	*stack_clone(t_stack **stack)
{
	t_stack	*new_stack;
	t_stack	*temp;

	new_stack = NULL;
	temp = *stack;
	while (temp != NULL)
	{
		ft_addtolist(&new_stack, temp->x);
		temp = temp->next;
	}
	return (new_stack);
}

void	apply_moves(t_group **group, int n_moves)
{
	int	i;

	i = 0;
	while (i <= n_moves)
	{
		if (list_sorted(&(*group)->clone_a) && !ft_stack_size((*group)->clone_b))
		{
			print_moves((*group)->array_moves, i);
			ft_free(group);
			exit(0);
		}
		if (!ft_strncmp((*group)->array_moves[i], "sa", 2))
			swap(&(*group)->clone_a, "sa");
		else if (!ft_strncmp((*group)->array_moves[i], "sb", 2))
			swap(&(*group)->clone_b, "sb");
		else if (!ft_strncmp((*group)->array_moves[i], "pb", 2))
			push(&(*group)->clone_b, &(*group)->clone_a, "pb");
		else if (!ft_strncmp((*group)->array_moves[i], "pa", 2))
			push(&(*group)->clone_a, &(*group)->clone_b, "pa");
		else if (!ft_strncmp((*group)->array_moves[i], "ra", 2))
			rotate(&(*group)->clone_a, "ra");
		else if (!ft_strncmp((*group)->array_moves[i], "rb", 2))
			rotate(&(*group)->clone_b, "rb");
		else if (!ft_strncmp((*group)->array_moves[i], "rra", 2))
			rev_rotate(&(*group)->clone_a, "rra");
		else if (!ft_strncmp((*group)->array_moves[i], "rrb", 2))
			rev_rotate(&(*group)->clone_b, "rrb");
		i++;
	}
	if (list_sorted(&(*group)->clone_a) && !ft_stack_size((*group)->clone_b))
	{
		print_moves((*group)->array_moves, i);
		ft_free(group);
		exit(0);
	}
}

int	move_on_stack_a(t_group *group, int n_moves)
{
	int		i;
	int		j;

	i = n_moves;
	while (i >= 0)
	{
		j = 0;
		while (group->array_moves[i][j] != '\0')
		{
			if (group->array_moves[i][j] == 'a')
			{
				if (group->array_moves[i][j - 1] == 'r' && group->array_moves[i][j - 2] == 'r')
					return (3);
				else if (group->array_moves[i][j - 1] == 'r')
					return (2);
				else if (group->array_moves[i][j - 1] == 's')
					return (1);
				else
					return (0);
			}
			j++;
		}
		i--;
	}
	return (0);
}

int	move_on_stack_b(t_group *group, int n_moves)
{
	int		i;
	int		j;

	i = n_moves;
	while (i >= 0)
	{
		j = 0;
		while (group->array_moves[i][j] != '\0')
		{
			if (group->array_moves[i][j] == 'b')
			{
				if (group->array_moves[i][j - 1] == 'r' && group->array_moves[i][j - 2] == 'r')
					return (3);
				else if (group->array_moves[i][j - 1] == 'r')
					return (2);
				else if (group->array_moves[i][j - 1] == 's')
					return (1);
				else
					return (0);
			}
			j++;
		}
		i--;
	}
	return (0);
}

void	void_sort_list_2(t_group *group, int n_moves, char *move)
{
	int	stack_size_a;
	int	stack_size_b;

	if (n_moves == group->max_moves)
		return ;
	group->clone_a = stack_clone(&group->a);
	group->clone_b = stack_clone(&group->b);
	put_move_array((group->array_moves), move, n_moves);
	apply_moves(&group, n_moves);
	stack_size_a = ft_stack_size(group->clone_a);
	stack_size_b = ft_stack_size(group->clone_b);
	ft_free_stack(&group->clone_a);
	ft_free_stack(&group->clone_b);
	if (move_on_stack_a(group, n_moves) != 1 && stack_size_a >= 2)
		put_move_array((group->array_moves), move, "sa");
	if (stack_size_a > 0)
	{
		if (move_on_stack_a(group, n_moves) != 3 && stack_size_a >= 2)
			void_sort_list_2(group, n_moves, "ra");
		if (move_on_stack_a(group, n_moves) != 2 && stack_size_a >= 2)
			void_sort_list_2(group, n_moves, "rra");
		if (move_on_stack_a(group, n_moves) != 0)
			void_sort_list_2(group, n_moves, "pb");
	}
	if (move_on_stack_b(group, n_moves) != 1 && stack_size_b >= 2)
		void_sort_list_2(group, n_moves, "sb");
	if (stack_size_b > 0)
	{
		if (move_on_stack_b(group, n_moves) != 3 && stack_size_b >= 2)
			void_sort_list_2(group, n_moves, "rb");
		if (move_on_stack_b(group, n_moves) != 2 && stack_size_b >= 2)
			void_sort_list_2(group, n_moves, "rrb");
		if (move_on_stack_b(group, n_moves) != 0)
			void_sort_list_2(group, n_moves, "pa");
	}
	void_sort_list_2(group, n_moves + 1, "sa");
	// void_sort_list_3(group, n_moves, "ra");
	// void_sort_list_3(group, n_moves, "rra");
	// void_sort_list_3(group, n_moves, "pb");
	// void_sort_list_3(group, n_moves, "sb");
	// void_sort_list_3(group, n_moves, "rb");
	// void_sort_list_3(group, n_moves, "rrb");
	// void_sort_list_3(group, n_moves, "pa");
	// void_sort_list_3(group, n_moves + 1, "sa");
	return ;
}

// void	void_sort_list_3(t_group *group, int n_moves, char *move)
// {
// 	int	stack_size_a;
// 	int	stack_size_b;

// 	if (n_moves == group->max_moves)
// 		return ;
// 	group->clone_a = stack_clone(&group->a);
// 	group->clone_b = stack_clone(&group->b);
// 	put_move_array((group->array_moves), move, n_moves);
// 	apply_moves(&group, n_moves);
// 	stack_size_a = ft_stack_size(group->clone_a);
// 	stack_size_b = ft_stack_size(group->clone_b);
// 	ft_free_stack(&group->clone_a);
// 	ft_free_stack(&group->clone_b);
// 	if (move_on_stack_a(group, n_moves) != 1 && stack_size_a >= 2)
// 		void_sort_list_2(group, n_moves + 1, "sa");
// 	if (stack_size_a > 0)
// 	{
// 		if (move_on_stack_a(group, n_moves) != 3 && stack_size_a >= 2)
// 			void_sort_list_2(group, n_moves + 1, "ra");
// 		if (move_on_stack_a(group, n_moves) != 2 && stack_size_a >= 2)
// 			void_sort_list_2(group, n_moves + 1, "rra");
// 		if (move_on_stack_a(group, n_moves) != 0)
// 			void_sort_list_2(group, n_moves + 1, "pb");
// 	}
// 	if (move_on_stack_b(group, n_moves) != 1 && stack_size_b >= 2)
// 		void_sort_list_2(group, n_moves + 1, "sb");
// 	if (stack_size_b > 0)
// 	{
// 		if (move_on_stack_b(group, n_moves) != 3 && stack_size_b >= 2)
// 			void_sort_list_2(group, n_moves + 1, "rb");
// 		if (move_on_stack_b(group, n_moves) != 2 && stack_size_b >= 2)
// 			void_sort_list_2(group, n_moves + 1, "rrb");
// 		if (move_on_stack_b(group, n_moves) != 0)
// 			void_sort_list_2(group, n_moves + 1, "pa");
// 	}
// 	return ;
// }

// void	void_sort_list_2(t_group *group, int n_moves, char *move)
// {
// 	int	stack_size_a;
// 	int	stack_size_b;

// 	if (n_moves == group->max_moves)
// 		return ;
// 	group->clone_a = stack_clone(&group->a);
// 	group->clone_b = stack_clone(&group->b);
// 	put_move_array((group->array_moves), move, n_moves);
// 	apply_moves(&group, n_moves);
// 	stack_size_a = ft_stack_size(group->clone_a);
// 	stack_size_b = ft_stack_size(group->clone_b);
// 	ft_free_stack(&group->clone_a);
// 	ft_free_stack(&group->clone_b);
// 	if (ft_strncmp(move, "sa", 2) && stack_size_a >= 2)
// 		void_sort_list_2(group, n_moves + 1, "sa");
// 	if (stack_size_a > 0)
// 	{
// 		if (ft_strncmp(move, "rra", 3) && stack_size_a >= 3)
// 			void_sort_list_2(group, n_moves + 1, "ra");
// 		if (ft_strncmp(move, "ra", 2) && stack_size_a >= 3)
// 			void_sort_list_2(group, n_moves + 1, "rra");
// 		if (ft_strncmp(move, "pa", 2))
// 			void_sort_list_2(group, n_moves + 1, "pb");
// 	}
// 	if (ft_strncmp(move, "sb", 2) && stack_size_b >= 2)
// 		void_sort_list_2(group, n_moves + 1, "sb");
// 	if (stack_size_b > 0)
// 	{
// 		if (ft_strncmp(move, "rrb", 3) && stack_size_b >= 3)
// 			void_sort_list_2(group, n_moves + 1, "rb");
// 		if (ft_strncmp(move, "rb", 2) && stack_size_b >= 3)
// 			void_sort_list_2(group, n_moves + 1, "rrb");
// 		if (ft_strncmp(move, "pb", 2))
// 			void_sort_list_2(group, n_moves + 1, "pa");
// 	}
// 	return ;
// }

// TODO Falta criar funcao em caso de erro
char	**create_array_moves(t_group **group, int max_moves)
{
	char	**array_moves;
	int		i;

	array_moves = malloc(sizeof(char *) * (max_moves + 1));
	if (!array_moves)
		deallocate(*group, 2);
	i = 0;
	while (i < max_moves)
	{
		array_moves[i] = malloc(sizeof(char) * 4);
		// if (!array_moves[i])
		// 	deallocate(group, 2);
		i++;
	}
	array_moves[i] = 0;
	return (array_moves);
}

t_group	*init_group(char **argv)
{
	t_group	*group;

	group = malloc(sizeof(t_group));
	if (!group)
		exit(write(2, "Error\n", 6));
	group->a = NULL;
	group->b = NULL;
	group->clone_a = NULL;
	group->clone_b = NULL;
	check_argv(argv, &group->a);
	if (!group->a)
		exit(write(2, "Error\n", 6));
	group->max_moves = calculate_max_moves(group->a);
	printf("max_moves: %d\n", group->max_moves);
	group->array_moves = create_array_moves(&group, group->max_moves);
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