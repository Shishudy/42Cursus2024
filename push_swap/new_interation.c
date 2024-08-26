/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_interation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:06:16 by rafasant          #+#    #+#             */
/*   Updated: 2024/08/26 19:24:57 by rafasant         ###   ########.fr       */
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
	printf("%s\n", "ft_free_stack");
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
	printf("%s\n", "ft_free");
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
    printf("move added: %s\n", array_moves[n_move]);
}

int	calculate_max_moves(t_stack *a)
{
	float	max_moves;
	int		stack_size;

	stack_size = ft_stack_size(a);
	max_moves = ((0.00961190856 * (stack_size * stack_size)) + (6.23285486 * stack_size) - 19.4045720);
	return ((int)max_moves - 1);
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
	while (array_moves[i] != 0 && i <= n_moves)
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
			write(1, array_moves[i], 2);
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
		printf("print move: %s\n", (*group)->array_moves[i]);
		if (list_sorted(&(*group)->clone_a) && !ft_stack_size((*group)->clone_b))
		{
			print_moves((*group)->array_moves, i);
			ft_free(group);
			return ;
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
		return ;
	}
}

void	void_sort_list_2(t_group *group, int n_moves, char *move)
{
	int	stack_size_a;
	int	stack_size_b;

	if (n_moves > group->max_moves)
		return ;
	printf("n_moves: %d\n", n_moves);
	group->clone_a = stack_clone(&group->a);
	group->clone_b = stack_clone(&group->b);
	stack_size_a = ft_stack_size(group->clone_a);
	printf("stack_size_a: %d\n", stack_size_a);
	stack_size_b = ft_stack_size(group->clone_b);
	printf("stack_size_b: %d\n", stack_size_b);
	put_move_array(&(group->array_moves[n_moves]), move, n_moves);
	apply_moves(&group, n_moves);
	if (ft_strncmp(move, "sa", 2) && stack_size_a >= 2)
		void_sort_list_2(group, n_moves + 1, "sa");
	if (stack_size_a != 0)
	{
		if (stack_size_a >= 2)
		{
			void_sort_list_2(group, n_moves + 1, "ra");
			void_sort_list_2(group, n_moves + 1, "rra");
		}
		void_sort_list_2(group, n_moves + 1, "pb");
	}
	if (ft_strncmp(move, "sb", 2) && stack_size_b >= 2)
		void_sort_list_2(group, n_moves + 1, "sb");
	if (stack_size_b != 0)
	{
		if (stack_size_b >= 2)
		{
			void_sort_list_2(group, n_moves + 1, "rb");
			void_sort_list_2(group, n_moves + 1, "rrb");
		}
		void_sort_list_2(group, n_moves + 1, "pa");
	}
	ft_free(&group);
	return;
}


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
		array_moves[i] = malloc(sizeof(char) * 3);
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