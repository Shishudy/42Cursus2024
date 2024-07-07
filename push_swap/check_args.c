/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:05:58 by rafasant          #+#    #+#             */
/*   Updated: 2024/07/07 12:54:10 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_sorted(t_stack **stack)
{
	t_stack	*temp;

	if (!stack)
		return (0);
	temp = *stack;
	while (temp->next)
	{
		if (temp->x > temp->next->x)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	deallocate(t_stack **stack, int message)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	if (message == 2)
		exit(0);
	if (message == 1)
		exit (write(1, "Error\n", 6));
}

void	ft_addtolist(t_stack **a, int x)
{
	t_stack	*temp;
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return ;
	new->x = x;
	new->next = NULL;
	if (!*a)
	{
		*a = new;
		return ;
	}
	temp = *a;
	while (temp->next && temp->x != x)
		temp = temp->next;
	if (temp->x == x)
	{
		free (new);
		deallocate(a, 1);
	}
	temp->next = new;
}

int	split_atoi(char **argv, t_stack **a)
{
	long int	value;
	int			sign;

	value = 0;
	sign = 1;
	while ((**argv == 32 || (**argv >= 9 && **argv <= 13)) && **argv)
		(*argv)++;
	if (**argv == '-')
	{
		sign = -1;
		(*argv)++;
	}
	if ((**argv < '0' || **argv > '9') && **argv != '\0')
		deallocate(a, 1);
	while (**argv >= '0' && **argv <= '9' && **argv != '\0')
	{
		if (value * 10 < value)
			deallocate(a, 1);
		value = value * 10 + **argv - '0';
		(*argv)++;
	}
	if (value * sign > 2147483647 || value * sign < -2147483648 || \
		(**argv != 32 && (**argv <= 9 || **argv >= 13) && **argv))
		deallocate(a, 1);
	return (value * sign);
}

void	check_argv(char **argv, t_stack **a)
{
	int		i;

	i = 1;
	while (argv[i])
	{
		ft_addtolist(a, split_atoi(&argv[i], a));
		i += !(*argv[i]);
	}
	if (list_sorted(a))
		deallocate(a, 2);
}