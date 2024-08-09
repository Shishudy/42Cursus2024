/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:53:13 by rafasant          #+#    #+#             */
/*   Updated: 2024/08/09 15:49:03 by rafasant         ###   ########.fr       */
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

void	print_moves(char **array_moves)
{
	int	i;

	i = 0;
	while (array_moves[i] != 0)
	{
		write(1, &array_moves[i], ft_strlen(array_moves[i]));
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
	printf("max_moves: %d\n", i);
	b = stack_clone(&a);
	push(b, a, "pb");
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
	i = 0;
	while (array_moves[i] && array_moves[i][0] != '\0')
	{
		printf("moves: %s\n", array_moves[i]);
		i++;
	}
	return 0;
}