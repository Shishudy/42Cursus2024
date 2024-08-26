/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:19:51 by rafasant          #+#    #+#             */
/*   Updated: 2024/08/26 19:03:58 by rafasant         ###   ########.fr       */
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
	exit(printf("sorted\n"));
	return (1);
}

void	deallocate(t_group *group, int message)
{
	t_stack	*temp;

	ft_free(&group);
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