#include <stdio.h>
#include "push_swap.h"

/*
	recursivo, colocando para dentro de um array cada um dos movimentos e depois retornando o array
	- ter um array de N tamanho, depois de colocar cada movimento verificar se aplicando esses movimentos à lista ela fica ordenada
	- fazer o calculo de nº de parametros passados para nº max de movimentos correspondentes
*/

void	put_move_array(char *array_moves, char *move)
{
	int	i;

	i = 0;
	if (array_moves[i] != '\0')
		ft_bzero(&array_moves[i], 4);
	while (move[i])
	{
		array_moves[i] = move[i];
		i++;
	}
	write(1, "move added\n", 12);
}

int	calculate_max_moves(t_stack *a)
{
	float	max_moves;
	int		stack_size;

	stack_size = ft_stack_size(a);
	max_moves = ((0.00961190856 * (stack_size * stack_size)) + (6.23285486 * stack_size) - 19.4045720);
	return ((int)max_moves - 1);
}

// int	int_sort_list(t_stack **clone_a, t_stack **clone_b, int n_moves, int max_moves, char *move, char **array_moves)
// {
// 	if (list_sorted(clone_a) && lst_size(clone_b) == 0)
// 		return (1);
// 	if (n_moves >= max_moves)
// 		return (n_moves - 1);
// 	put_move_array((array_moves[n_moves]), move);
// 	if (ft_strncmp(move, "sa", 3) && ft_lstsize(clone_a) >= 2)
// 	{
// 		moves = sort_list(clone_a, clone_b, moves + 1, "sa", array_moves);
// 		moves = sort_list(clone_a, clone_b, moves - 1, "sa", array_moves);
// 	}
// 	if (ft_lstsize(clone_a) != 0)
// 	{
// 		if (ft_lstsize(clone_a) >= 2)
// 		{
// 			moves = sort_list(clone_a, clone_b, moves + 1, "ra", array_moves);
// 			moves = sort_list(clone_a, clone_b, moves - 1, "ra", array_moves);
// 			moves = sort_list(clone_a, clone_b, moves + 1, "rra", array_moves);
// 			moves = sort_list(clone_a, clone_b, moves - 1, "rra", array_moves);
// 		}
// 		moves = sort_list(clone_a, clone_b, moves + 1, "pb", array_moves);
// 		moves = sort_list(clone_a, clone_b, moves - 1, "pb", array_moves);
// 	}
// 	if (ft_lstsize(clone_a) >= 2 && ft_lstsize(clone_b) >= 2)
// 	{
// 		moves = sort_list(clone_a, clone_b, moves + 1, "rrr", array_moves);
// 		moves = sort_list(clone_a, clone_b, moves - 1, "rrr", array_moves);
// 		moves = sort_list(clone_a, clone_b, moves + 1, "ss", array_moves);
// 		moves = sort_list(clone_a, clone_b, moves - 1, "ss", array_moves);
// 	}
// 	if (ft_strncmp(move, "sb", 3) && ft_lstsize(clone_b) >= 2)
// 	{
// 		moves = sort_list(clone_a, clone_b, moves + 1, "sb", array_moves);
// 		moves = sort_list(clone_a, clone_b, moves - 1, "sb", array_moves);
// 	}
// 	if (ft_lstsize(clone_b) != 0)
// 	{
// 		if (ft_lstsize(clone_b) >= 2)
// 		{
// 			moves = sort_list(clone_a, clone_b, moves + 1, "rb", array_moves);
// 			moves = sort_list(clone_a, clone_b, moves - 1, "rb", array_moves);
// 			moves = sort_list(clone_a, clone_b, moves + 1, "rrb", array_moves);
// 			moves = sort_list(clone_a, clone_b, moves - 1, "rrb", array_moves);
// 		}
// 		moves = sort_list(clone_a, clone_b, moves + 1, "pa", array_moves);
// 		moves = sort_list(clone_a, clone_b, moves - 1, "pa", array_moves);
// 	}
// 	return (moves - 1);
// 	// if (!list_sorted(clone_a) || clone_b || moves == 5500)
// 	// 	return (moves - 1);
// }

// void	void_sort_list(t_stack **clone_a, t_stack **clone_b, int n_moves, int max_moves, char *move, char **array_moves)
// {
// 	if (list_sorted(clone_a) && lst_size(clone_b) == 0)
// 		return;
// 	if (n_moves >= max_moves)
// 		return;
// 	put_move_array((array_moves[n_moves]), move);
// 	if (ft_strncmp(move, "sa", 3) && ft_lstsize(clone_a) >= 2)
// 	{
// 		sort_list(clone_a, clone_b, n_moves + 1, "sa", array_moves);
// 		sort_list(clone_a, clone_b, n_moves - 1, "sa", array_moves);
// 	}
// 	if (ft_lstsize(clone_a) != 0)
// 	{
// 		if (ft_lstsize(clone_a) >= 2)
// 		{
// 			sort_list(clone_a, clone_b, n_moves + 1, "ra", array_moves);
// 			sort_list(clone_a, clone_b, n_moves - 1, "ra", array_moves);
// 			sort_list(clone_a, clone_b, n_moves + 1, "rra", array_moves);
// 			sort_list(clone_a, clone_b, n_moves - 1, "rra", array_moves);
// 		}
// 		sort_list(clone_a, clone_b, n_moves + 1, "pb", array_moves);
// 		sort_list(clone_a, clone_b, n_moves - 1, "pb", array_moves);
// 	}
// 	if (ft_lstsize(clone_a) >= 2 && ft_lstsize(clone_b) >= 2)
// 	{
// 		sort_list(clone_a, clone_b, n_moves + 1, "rrr", array_moves);
// 		sort_list(clone_a, clone_b, n_moves - 1, "rrr", array_moves);
// 		sort_list(clone_a, clone_b, n_moves + 1, "ss", array_moves);
// 		sort_list(clone_a, clone_b, n_moves - 1, "ss", array_moves);
// 	}
// 	if (ft_strncmp(move, "sb", 3) && ft_lstsize(clone_b) >= 2)
// 	{
// 		sort_list(clone_a, clone_b, n_moves + 1, "sb", array_moves);
// 		sort_list(clone_a, clone_b, n_moves - 1, "sb", array_moves);
// 	}
// 	if (ft_lstsize(clone_b) != 0)
// 	{
// 		if (ft_lstsize(clone_b) >= 2)
// 		{
// 			sort_list(clone_a, clone_b, n_moves + 1, "rb", array_moves);
// 			sort_list(clone_a, clone_b, n_moves - 1, "rb", array_moves);
// 			sort_list(clone_a, clone_b, n_moves + 1, "rrb", array_moves);
// 			sort_list(clone_a, clone_b, n_moves - 1, "rrb", array_moves);
// 		}
// 		sort_list(clone_a, clone_b, n_moves + 1, "pa", array_moves);
// 		sort_list(clone_a, clone_b, n_moves - 1, "pa", array_moves);
// 	}
// 	return;
// 	// if (!list_sorted(clone_a) || clone_b || moves == 5500)
// 	// 	return (moves - 1);
// }

void	ft_free(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	while (*a)
	{
		temp = (*a)->next;
		free(*a);
		*a = temp;
	}
	while (*b)
	{
		temp = (*b)->next;
		free(*b);
		*b = temp;
	}
}

void	apply_moves(t_stack **clone_a, t_stack **clone_b, char **array_moves)
{
	int	i;

	i = -1;
	while (array_moves[++i])
	{
		if (ft_strncmp(array_moves[i], "sa", 3))
			swap(clone_a, NULL, array_moves[i]);
		else if (ft_strncmp(array_moves[i], "ra", 3))
			rotate(clone_a, NULL, array_moves[i]);
		else if (ft_strncmp(array_moves[i], "rra", 3))
			rev_rotate(clone_a, NULL, array_moves[i]);
		else if (ft_strncmp(array_moves[i], "pa", 3))
			push(clone_a, clone_b, array_moves[i]);
		else if (ft_strncmp(array_moves[i], "pb", 3))
			push(clone_b, clone_a, array_moves[i]);
		else if (ft_strncmp(array_moves[i], "sb", 3))
			swap(clone_b, NULL, array_moves[i]);
		else if (ft_strncmp(array_moves[i], "rb", 3))
			rotate(clone_b, NULL, array_moves[i]);
		else if (ft_strncmp(array_moves[i], "rrb", 3))
			rev_rotate(clone_b, NULL, array_moves[i]);
		else if (ft_strncmp(array_moves[i], "rr", 3))
			rotate(clone_a, clone_b, array_moves[i]);
		else if (ft_strncmp(array_moves[i], "rrr", 3))
			rotate(clone_a, clone_b, array_moves[i]);
		else if (ft_strncmp(array_moves[i], "ss", 3))
			swap(clone_a, clone_b, array_moves[i]);
	}
}

void	print_moves(char **array_moves)
{
	int	i;

	i = 0;
	while (array_moves[i] != '\0')
	{
		write(1, &array_moves[i], ft_strlen(array_moves[i]));
		write(1, "\n", 1);
		i++;
	}
}

void	void_sort_list_2(t_stack **clone_a, t_stack **clone_b, int n_moves, int max_moves, char *move, char **array_moves)
{
	int	stack_size_a;
	int	stack_size_b;

	apply_moves(clone_a, clone_b, array_moves);
	if ((list_sorted(clone_a) && stack_size_b == 0) || n_moves >= max_moves)
		return (ft_free(clone_a, clone_b));
	put_move_array((array_moves[n_moves]), move);
	stack_size_a = ft_stack_size(*clone_a);
	stack_size_b = ft_stack_size(*clone_b);
	if (ft_strncmp(move, "sa", 3) && stack_size_a >= 2)
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
	if (stack_size_a >= 2 && stack_size_b >= 2)
	{
		void_sort_list_2(clone_a, clone_b, n_moves + 1, max_moves, "rrr", array_moves);
		void_sort_list_2(clone_a, clone_b, n_moves + 1, max_moves, "ss", array_moves);
	}
	if (ft_strncmp(move, "sb", 3) && stack_size_b >= 2)
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

t_stack	*stack_clone(t_stack **stack)
{
	t_stack	*new_stack;
	t_stack	*temp;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	temp = *stack;
	while (temp != NULL)
	{
		ft_addtolist(&new_stack, temp->x);
		temp = temp->next;
	}
	return (new_stack);
}

int main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_stack		*temp;
	static char	array_moves[5500][4];
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
	// temp = a;
	// i = 0;
	// while (temp != NULL)
	// {
	// 	i++;
	// 	printf("before: %d\n", temp->x);
	// 	temp = temp->next;
	// }
	b = stack_clone(&a);
	void_sort_list_2(stack_clone(&a), stack_clone(&b), 0, calculate_max_moves(a), "sa", array_moves);
	while (b != NULL)
	{
		i++;
		printf("after: %d\n", b->x);
		b = b->next;
	}
	i = 0;
	while (array_moves[i] && array_moves[i][0] != '\0')
	{
		printf("moves: %s\n", array_moves[i]);
		i++;
	}
	// i = 0;
	// while (i < 5)
	// {
	// 	swap(&a, NULL, "sa\n");
	// 	put_move_array((array_moves[i]), "sa\n");
	// 	i++;
	// }
	return 0;
}

// void (*p[4]) (t_stack **a, t_stack **b, char *move);

// int main(void)
// {
// 	int op;
// 	int i;
// 	t_stack	*a;

// 	p[0] = push;
// 	p[1] = swap;
// 	p[2] = rotate;
// 	p[3] = rev_rotate;
// 	a = NULL;
// 	while (i < 10)
// 	{
// 		ft_addtolist(&a, i);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < 5)
// 	{
// 		p[1](&a, NULL, "sa\n");
// 		i++;
// 	}
// 	while (a != NULL)
// 	{
// 		printf("a: %d\n", a->x);
// 		a = a->next;
// 	}
// 	return 0;
// }