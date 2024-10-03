/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:05:58 by rafasant          #+#    #+#             */
/*   Updated: 2024/10/03 21:39:18 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

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

void	split_atoi(t_group *group, char **argv)
{
	while ((**argv == 32 || (**argv >= 9 && **argv <= 13)) && **argv)
		(*argv)++;
	if (**argv == '\0')
		group->sign = 0;
	if (**argv == '-' && (**argv + 1 < '0' || **argv + 1 > '9'))
	{
		group->sign = -1;
		(*argv)++;
	}
	if (((**argv < '0' || **argv > '9') && **argv != '\0') || \
	(group->sign == -1 && **argv == '\0'))
		deallocate(group, 1);
	while (**argv >= '0' && **argv <= '9' && **argv != '\0')
	{
		if (group->x * 10 < group->x)
			deallocate(group, 1);
		group->x = group->x * 10 + **argv - '0';
		(*argv)++;
	}
	if (group->x * group->sign > 2147483647 || group->x * group->sign < \
	-2147483648 || (**argv != 32 && (**argv <= 9 || **argv >= 13) && **argv))
		deallocate(group, 1);
	group->x = group->x * group->sign;
}

void	check_argv(t_group *group, char **argv)
{
	int		i;

	i = 1;
	while (argv[i])
	{
		group->sign = 1;
		group->x = 0;
		split_atoi(group, &argv[i]);
		if (group->sign != 0)
			ft_addtolist(group, group->x);
		i += !(*argv[i]);
	}
	if (list_sorted(group->a))
		deallocate(group, 0);
}
