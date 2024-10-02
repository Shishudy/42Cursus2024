/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:19:51 by rafasant          #+#    #+#             */
/*   Updated: 2024/10/02 21:12:07 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

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
	if (group->a)
		ft_free_stack(&group->a);
	if (group->b)
		ft_free_stack(&group->b);
	if (group->chunk)
		free(group->chunk);
	free(group);
	if (message == 2)
		exit(0);
	else if (message == 1)
		exit (write(2, "Error\n", 6));
	else if (message == 0)
		exit (write(2, "KO\n", 6));
}
