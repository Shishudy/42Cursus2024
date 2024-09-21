/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:05:58 by rafasant          #+#    #+#             */
/*   Updated: 2024/09/20 22:28:42 by rafasant         ###   ########.fr       */
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

int	list_sorted(t_stack **stack)
{
	t_stack	*temp;

	if (!stack)
		return (0);
	temp = *stack;
	if (temp)
	{
		while (temp->next != NULL)
		{
			if (temp->x > temp->next->x)
				return (0);
			temp = temp->next;
		}
	}
	return (1);
}

void	ft_addtolist(t_group *group, int x)
{
	t_stack	*temp;
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return ;
	new->x = x;
	new->next = NULL;
	if (!group->a)
	{
		group->a = new;
		return ;
	}
	temp = group->a;
	while (temp->next && temp->x != x)
		temp = temp->next;
	if (temp->x == x)
	{
		free (new);
		deallocate(group, 1);
	}
	temp->next = new;
}

int	split_atoi(t_group *group, char **argv)
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
		deallocate(group, 1);
	while (**argv >= '0' && **argv <= '9' && **argv != '\0')
	{
		if (value * 10 < value)
			deallocate(group, 1);
		value = value * 10 + **argv - '0';
		(*argv)++;
	}
	if (value * sign > 2147483647 || value * sign < -2147483648 || \
		(**argv != 32 && (**argv <= 9 || **argv >= 13) && **argv))
		deallocate(group, 1);
	return (value * sign);
}

void	check_argv(t_group *group, char **argv)
{
	int		i;

	i = 1;
	while (argv[i])
	{
		ft_addtolist(group, split_atoi(group, &argv[i]));
		i += !(*argv[i]);
	}
	if (list_sorted(&group->a))
		deallocate(group, 2);
}
