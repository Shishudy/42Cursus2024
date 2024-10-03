/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:19:51 by rafasant          #+#    #+#             */
/*   Updated: 2024/10/03 21:00:21 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker.h"

int	list_sorted(t_stack *stack)
{
	t_stack	*temp;

	if (!stack)
		return (0);
	temp = stack;
	while (temp->next)
	{
		if (temp->x > temp->next->x)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

void	deallocate(t_group *group, int message)
{
	if (group->a)
		ft_free_stack(&group->a);
	if (group->b)
		ft_free_stack(&group->b);
	free(group);
	if (message == 0)
		exit(write(1, "OK\n", 3));
	else if (message == 1)
		exit (write(1, "KO\n", 3));
	else if (message == 2)
		exit (write(2, "Error\n", 6));
	else if (message == 3)
		exit (0);
}
