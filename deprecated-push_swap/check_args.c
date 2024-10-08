/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:05:58 by rafasant          #+#    #+#             */
/*   Updated: 2024/08/19 15:28:00 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		deallocate2(a, 1);
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
		deallocate2(a, 1);
	while (**argv >= '0' && **argv <= '9' && **argv != '\0')
	{
		if (value * 10 < value)
			deallocate2(a, 1);
		value = value * 10 + **argv - '0';
		(*argv)++;
	}
	if (value * sign > 2147483647 || value * sign < -2147483648 || \
		(**argv != 32 && (**argv <= 9 || **argv >= 13) && **argv))
		deallocate2(a, 1);
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
		deallocate2(a, 2);
}