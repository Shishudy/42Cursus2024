/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:32:39 by rafasant          #+#    #+#             */
/*   Updated: 2024/09/19 18:05:57 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_group *group)
{
	if (group->size_a == 2)
		swap(&group->a, "sa");
	else if (group->a->x > group->a->next->x && group->a->next->x > \
	group->a->next->next->x)
	{
		swap(&group->a, "sa");
		rev_rotate(&group->a, "rra");
	}
	else if (group->a->x < group->a->next->x && group->a->x > \
	group->a->next->next->x)
		rev_rotate(&group->a, "rra");
	else if (group->a->x < group->a->next->x && group->a->next->next->x < \
	group->a->next->x)
	{
		swap(&group->a, "sa");
		rotate(&group->a, "ra");
	}
	else if (group->a->x > group->a->next->x && group->a->next->next->x > \
	group->a->x)
		swap(&group->a, "sa");
	else if (group->a->x > group->a->next->x && group->a->x > \
	group->a->next->next->x)
		rotate(&group->a, "ra");
}

void	sort_5(t_group *group)
{
	push_cheapest(group, calculate_cost(group->a, group->size_a, find_value(group, 1)));
	push_cheapest(group, calculate_cost(group->a, group->size_a, find_value(group, 1)));
	sort_3(group);
	push(&group->a, &group->b, "pa", group);
	push(&group->a, &group->b, "pa", group);
	if (group->a->x > group->a->next->x)
		swap(&group->a, "sa");
}

void	sort_5(t_group *group)
{
	while ()
}
