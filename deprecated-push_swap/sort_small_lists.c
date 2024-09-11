/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_lists.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:11:35 by rafasant          #+#    #+#             */
/*   Updated: 2024/07/07 12:15:21 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **a, t_stack **b)
{
	if ((*a)->x > (*a)->next->x && (*a)->x < (*a)->next->next->x)
		swap(a, NULL, "sa");
	else if ((*a)->x > (*a)->next->x && (*a)->x > (*a)->next->next->x)
		rotate(a, NULL, "ra");
	else if ((*a)->x < (*a)->next->x && (*a)->next->x > (*a)->next->next->x)
	{
		swap(a, NULL, "sa");
		rotate(a, NULL, "ra");
	}
	else if ((*a)->x > (*a)->next->x && (*a)->next->x > (*a)->next->next->x)
	{
		swap(a, NULL, "sa");
		rev_rotate(a, NULL, "rra");
	}
	else if ((*a)->x > (*a)->next->x && (*a)->next->x > (*a)->next->next->x)
	{
		swap(a, NULL, "sa");
		rev_rotate(a, NULL, "rra");
	}
	else
		rev_rotate(a, NULL, "rra");
}

void	sort_4(t_stack **a, t_stack **b)
{

}

void	sort_5(t_stack **a, t_stack **b)
{
	
}