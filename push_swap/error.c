/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:19:51 by rafasant          #+#    #+#             */
/*   Updated: 2024/09/14 21:54:31 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	deallocate(t_group *group, int message)
{
	ft_free_stack(&group->a);
	if (group->b)
		ft_free_stack(&group->b);
	free(group);
	if (message == 2)
		exit(0);
	if (message == 1)
		exit (write(1, "Error\n", 6));
}

void	deallocate2(t_stack **stack, int message)
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