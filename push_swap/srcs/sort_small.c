/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:32:39 by rafasant          #+#    #+#             */
/*   Updated: 2024/10/02 18:16:16 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	sort_3(t_group *group)
{
	if (list_sorted(group->a))
		return ;
	if (group->size_a == 2)
		swap(&group->a, "sa", 0);
	else if (group->a->x > group->a->next->x && group->a->next->x > \
	group->a->next->next->x)
	{
		swap(&group->a, "sa", 0);
		rev_rotate(&group->a, "rra", 0);
	}
	else if (group->a->x < group->a->next->x && group->a->x > \
	group->a->next->next->x)
		rev_rotate(&group->a, "rra", 0);
	else if (group->a->x < group->a->next->x && group->a->next->next->x < \
	group->a->next->x)
	{
		swap(&group->a, "sa", 0);
		rotate(&group->a, "ra", 0);
	}
	else if (group->a->x > group->a->next->x && group->a->next->next->x > \
	group->a->x)
		swap(&group->a, "sa", 0);
	else if (group->a->x > group->a->next->x && group->a->x > \
	group->a->next->next->x)
		rotate(&group->a, "ra", 0);
}

void	re_sort_3(t_group *group)
{
	if (list_sorted(group->a))
		return ;
	rotate(&group->a, "ra", 0);
	swap(&group->a, "sa", 0);
	rev_rotate(&group->a, "rra", 0);
}

void	sort_5(t_group *group)
{
	int	cost_top;
	int	cost_bot;

	if (list_sorted(group->a))
		return ;
	group->sort->control = 0;
	while (group->sort->control != 2)
	{
		cost_top = calculate_cost(group->a, group->size_a, find_value(group->a, 1), 1);
		cost_bot = calculate_cost(group->a, group->size_a, find_value(group->a, 1), -1);
		if (-cost_bot < cost_top)
			cost_top = cost_bot;
		push_cheapest_a(group, cost_top);
		if (list_sorted(group->a))
			break ;
	}
	sort_3(group);
	while (group->sort->control != 0)
	{
		push(&group->a, &group->b, "pa", group, 0);
		if (group->a->x > group->a->next->x)
			swap(&group->a, "sa", 0);
		group->sort->control--;
	}
}

void	sort_less_10(t_group *group)
{
	int	cost_top;
	int	cost_bot;
	
	group->chunk->chunk_size = group->size_a - 5;
	start_chunk(group);
	end_chunk(group);
	group->sort->control2 = 0;
	while (group->size_a >= 5)
		push_cheapest_a(group, find_cheapest(group->a, group->chunk->start, group->chunk->end, group->size_a));
	sort_5(group);
	while (group->sort->control2)
	{
		if (group->size_b == 1)
			return (push(&group->a, &group->b, "pa", group, 0));
		cost_top = calculate_cost(group->b, group->size_b, find_value(group->b, 2), 1);
		cost_bot = calculate_cost(group->b, group->size_b, find_value(group->b, 2), -1);
		if (-cost_bot < cost_top)
			cost_top = cost_bot;
		push_cheapest_b(group, cost_top);
		sort_3(group);
		group->sort->control2--;
	}
}
