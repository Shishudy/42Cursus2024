/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:50:55 by rafasant          #+#    #+#             */
/*   Updated: 2024/09/19 18:02:50 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	send_pb(t_group *group, int top, int bottom)
{
	if (top <= bottom)
	{
		while (top-- != 0)
			rotate(&group->a, "ra");
		push(&group->b, &group->a, "pb", group);
	}
	else if (top > bottom)
	{
		while (bottom-- != 0)
			rev_rotate(&group->a, "rra");
		push(&group->b, &group->a, "pb", group);
	}
	group->size_b++;
	group->size_a--;
}

int	gv_i(t_stack *a, int element)
{
	t_stack	*temp;
	int		index_a;

	temp = a;
	index_a = 0;
	while (temp->next != NULL && element != temp->x)
	{
		index_a++;
		temp = temp->next;
	}
	return (index_a);
}

int	numero_movi(t_stack *a, int end)
{
	t_stack	*temp;
	t_stack	*clone;
	int		i;

	clone = clone_list(a);
	temp = clone;
	sort_list(temp);
	i = 1;
	while (temp->next != NULL && temp->x != end)
	{
		i++;
		temp = temp->next;
	}
	ft_free_stack(&clone);
	return (i);
}


// void	best_move(t_group *group, int start, int end)
// {
// 	int		top;
// 	int		flag;

// 	group->chunk->i = numero_movi(group->a, end);
// 	group->chunk->md_pnt = midpoint(group->a, group->chunk->i);
// 	while (group->a && group->chunk->i-- != 0)
// 	{
// 		flag = 0;
// 		group->chunk->temp = (group->a);
// 		while (group->chunk->temp->next != NULL)
// 		{
// 			if ((group->chunk->temp->x >= start && group->chunk->temp->x <= end) && flag == 0)
// 			{
// 				top = group->chunk->temp->x;
// 				flag = 1;
// 			}
// 			if (group->chunk->temp->x >= start && group->chunk->temp->x <= end)
// 				group->chunk->bottom = group->chunk->temp->x;
// 			group->chunk->temp = group->chunk->temp->next;
// 		}
// 		send_pb(group, gv_i(group->a, top), (group->size_a - gv_i(group->a, group->chunk->bottom)));
// 		if (group->size_b > 1 && (group->b)->x < group->chunk->md_pnt)
// 			rotate(&group->b, "rb");
// 	}
// }

void	end_chunk_top(t_group *group)
{
	t_stack	*top;
	t_stack	*bot;

	bot = group->b;
	while (bot->next != NULL)
		bot = bot->next;
	top = group->b;
	while (top->next->x > bot->x)
		top = top->next;
	group->bf->end_chunk = top->x;
}

// void	chunk_midpoint(t_group *group)
// {

// }

void	find_best_friend(t_group *group)
{
	t_stack	*temp;
	int		bfa;

	temp = group->b;
	bfa = temp->x;
	while (temp != NULL && temp->x != group->bf->end_chunk)
	{
		if (temp->x > group->a->x && temp->x > bfa)
			bfa = temp->x;
		temp = temp->next;
	}
	temp = group->b;
	while (temp->x != bfa)
	{
		rotate(&group->b, "rb");
		temp = temp->next;
	}
}

// void	sort_back_a(t_group *group)
// {
// 	push(&group->a, &group->b, "pa");
// 	group->size_b--;
// 	group->size_a++;
// 	while (group->size_b)
// 	{
// 		end_chunk_top(group);
// 		if (group->size_a == 1)
// 			find_best_friend(group);
// 		while ()
// 		{
			
// 		}
// 	}
// }

// void	find_cheapest_a(t_group *group)
// {

// }

void	start_chunk(t_group *group)
{
	t_stack	*temp;
	t_stack	*clone;

	clone = clone_list(group->a);
	temp = clone;
	sort_list(temp);
	group->chunk->start = temp->x;
	ft_free_stack(&clone);
}

void	end_chunk(t_group *group)
{
	t_stack	*temp;
	t_stack	*clone;

	clone = clone_list(group->a);
	temp = clone;
	sort_list(temp);
	group->chunk->end = 0;
	while (temp->next != NULL && group->chunk->end != group->chunk->chunk_size)
	{
		group->chunk->end++;
		temp = temp->next;
	}
	group->chunk->end = temp->x;
	ft_free_stack(&clone);
}

int	cnt_rec(t_stack *stack, int end_chunk, int value)
{
	if (stack == NULL)
		return (value);
	if (stack->x <= end_chunk)
		value = stack->x;
	return (cnt_rec(stack->next, end_chunk, value));
}

int	find_cheapest(t_group *group)
{
	t_stack	*temp;
	int	cost_top;
	int	cost_bot;

	temp = group->a;
	while (temp != NULL && temp->x > group->chunk->end)
		temp = temp->next;
	cost_top = calculate_cost(group->a, group->size_a, group->a->x);
	cost_bot = calculate_cost(group->a, group->size_a, cnt_rec(group->a, group->chunk->end, group->a->x));
	// printf("cost_top: %d\n", cost_top);
	// printf("cost_bot: %d\n", cost_bot);
	if (-cost_bot < cost_top)
		cost_top = cost_bot;
	printf("cost_top: %d\n", cost_top);
	return (cost_top);
}

void	midpoint(t_group *group)
{
	t_stack	*temp;
	t_stack	*clone;

	clone = clone_list(group->a);
	temp = clone;
	sort_list(temp);
	group->chunk->midpoint = group->chunk->chunk_size / 2;
	while (group->chunk->midpoint-- != 0 && temp->next != NULL)
		temp = temp->next;
	group->chunk->midpoint = temp->x;
	ft_free_stack(&clone);
}

void	sort_to_b(t_group *group)
{
	t_stack	*temp;
	int		temp_chunk;

	temp = group->a;
	while (group->size_a > 5)
	{
		start_chunk(group);
		end_chunk(group);
		midpoint(group);
		// printf("group->chunk->start: %d\n", group->chunk->start);
		// printf("group->chunk->end: %d\n", group->chunk->end);
		// printf("group->chunk->midpoint: %d\n", group->chunk->midpoint);
		temp_chunk = group->chunk->chunk_size;
		while (temp_chunk > 0)
		{
			push_cheapest(group, find_cheapest(group));
			if (group->b->x < group->chunk->midpoint && group->size_b > 2)
				rotate(&group->b, "rb");
			temp_chunk--;
		}
	}
	// printf("%d\n", group->chunk->start);
	// printf("%d\n", group->chunk->end);
}

// void	sort_biggest(t_group *group)
// {
// 	while (group->size_a != 0)
// 		best_move(group);
// 	// add_to_buffer("");
// 	// sort_back_a(group);
// 	// chunk_midpoint(group);
// }