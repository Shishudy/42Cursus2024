/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:53:13 by rafasant          #+#    #+#             */
/*   Updated: 2024/08/17 15:43:23 by rafasant         ###   ########.fr       */
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

void    put_move_array(char **array_moves, char *move, int n_move)
{
    int i;

	i = 0;
    if (!array_moves[n_move])
        array_moves[n_move] = malloc(sizeof(char) * ft_strlen(move) + 1);
	else
	{
		while (array_moves[n_move][i] != '\0')
			array_moves[n_move][i] = '\0';
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

void	print_moves(char **array_moves)
{
	int	i;

	i = 0;
	while (array_moves[i] != 0)
	{
		if (!ft_strncmp(array_moves[i], "sa", 2) && !ft_strncmp(array_moves[i + 1], "sb", 2))
			i += write(1, "ss", 2) - 1;
		else if (!ft_strncmp(array_moves[i], "sb", 2) && !ft_strncmp(array_moves[i + 1], "sa", 2))
			i += write(1, "ss", 2) - 1;
		else if (!ft_strncmp(array_moves[i], "ra", 2) && !ft_strncmp(array_moves[i + 1], "rb", 2))
			i += write(1, "rr", 2) - 1;
		else if (!ft_strncmp(array_moves[i], "rb", 2) && !ft_strncmp(array_moves[i + 1], "ra", 2))
			i += write(1, "rr", 2) - 1;
		else if (!ft_strncmp(array_moves[i], "rra", 3) && !ft_strncmp(array_moves[i + 1], "rrb", 3))
			i += write(1, "rrr", 3) - 2;
		else if (!ft_strncmp(array_moves[i], "rrb", 3) && !ft_strncmp(array_moves[i + 1], "rra", 3))
			i += write(1, "rrr", 3) - 2;
		else
			write(1, array_moves[i], ft_strlen(array_moves[i]));
		write(1, "\n", 1);
		i++;
	}
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

void	apply_moves(t_stack **clone_a, t_stack **clone_b, char **array_moves)
{
	int	i;

	i = 0;
	while (array_moves[i])
	{
		if (!ft_strncmp(array_moves[i], "sa", 2))
			swap(clone_a, "sa");
		else if (!ft_strncmp(array_moves[i], "sb", 2))
			swap(clone_b, "sb");
		else if (!ft_strncmp(array_moves[i], "pb", 2))
			push(clone_b, clone_a, "pb");
		else if (!ft_strncmp(array_moves[i], "pa", 2))
			push(clone_a, clone_b, "pa");
		else if (!ft_strncmp(array_moves[i], "ra", 2))
			rotate(clone_a, "ra");
		else if (!ft_strncmp(array_moves[i], "rb", 2))
			rotate(clone_b, "rb");
		else if (!ft_strncmp(array_moves[i], "rra", 2))
			rev_rotate(clone_a, "rra");
		else if (!ft_strncmp(array_moves[i], "rrb", 2))
			rev_rotate(clone_b, "rrb");
		i++;
	}
}

void	ft_free(t_stack **clone_a, t_stack **clone_b)
{
	t_stack *temp;

	temp = *clone_a;
	while (*clone_a)
	{
		temp = (*clone_a)->next;
		free(*clone_a);
		*clone_a = temp;
	}
	temp = *clone_b;
	while (*clone_b)
	{
		temp = (*clone_b)->next;
		free(*clone_b);
		*clone_b = temp;
	}
}

void	void_sort_list_2(t_stack **clone_a, t_stack **clone_b, int n_moves, int max_moves, char *move, char **array_moves)
{
	int	stack_size_a;
	int	stack_size_b;

	stack_size_a = ft_stack_size(*clone_a);
	printf("stack_size_a: %d\n", stack_size_a);
	stack_size_b = ft_stack_size(*clone_b);
	printf("stack_size_b: %d\n", stack_size_b);
	apply_moves(clone_a, clone_b, array_moves);
	if ((list_sorted(clone_a) && stack_size_b == 0) || n_moves >= max_moves)
		return (ft_free(clone_a, clone_b));
	put_move_array((&array_moves[n_moves]), move, n_moves);
	if (ft_strncmp(move, "sa", 2) && stack_size_a >= 2)
		void_sort_list_2(clone_a, clone_b, n_moves + 1, max_moves, "sa", array_moves);
	if (stack_size_a != 0)
	{
		if (stack_size_a >= 2)
		{
			void_sort_list_2(clone_a, clone_b, n_moves + 1, max_moves, "ra", array_moves);
			void_sort_list_2(clone_a, clone_b, n_moves + 1, max_moves, "rra", array_moves);
		}
		void_sort_list_2(clone_a, clone_b, n_moves + 1, max_moves, "pb", array_moves);
	}
	if (ft_strncmp(move, "sb", 2) && stack_size_b >= 2)
		void_sort_list_2(clone_a, clone_b, n_moves + 1, max_moves, "sb", array_moves);
	if (stack_size_b != 0)
	{
		if (stack_size_b >= 2)
		{
			void_sort_list_2(clone_a, clone_b, n_moves + 1, max_moves, "rb", array_moves);
			void_sort_list_2(clone_a, clone_b, n_moves + 1, max_moves, "rrb", array_moves);
		}
		void_sort_list_2(clone_a, clone_b, n_moves + 1, max_moves, "pa", array_moves);
	}
	ft_free(clone_a, clone_b);
	return;
}

int main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_stack		*temp;
	char	**array_moves;
	int			i;

	a = NULL;
	b = NULL;
	i = 0;
	if (argc < 2)
		return (0);
	check_argv(argv, &a);
	if (!a)
		return (0);
	i = calculate_max_moves(a);
	printf("max_moves: %d\n", i);
	array_moves = malloc(sizeof(char *) * i + 1);
	void_sort_list_2(&a, &b, 0, i, "sa", array_moves);
	while (a != NULL)
	{
		i++;
		printf("a: %d\n", a->x);
		a = a->next;
	}
	while (b != NULL)
	{
		i++;
		printf("b: %d\n", b->x);
		b = b->next;
	}
	print_moves(array_moves);
	return 0;
}