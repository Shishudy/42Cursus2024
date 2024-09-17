/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:50:55 by rafasant          #+#    #+#             */
/*   Updated: 2024/09/17 23:36:12 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_list(t_stack *root)
{
	t_stack	*current;
	t_stack	*index;
	int		temp;

	if (!root)
		return ;
	temp = 0;
	index = NULL;
	current = root;
	while (current != NULL)
	{
		index = current->next;
		while (index != NULL)
		{
			if (current->x > index->x)
			{
				temp = current->x;
				current->x = index->x;
				index->x = temp;
			}
			index = index->next;
		}
		current = current->next;
	}
}

t_stack	*clone_list(t_stack *root)
{
	t_stack	*new_list;
	t_stack	*new_node;
	t_stack	*prev;
	t_stack	*curr;

	prev = NULL;
	new_list = NULL;
	curr = root;
	while (curr != NULL)
	{
		new_node = malloc(sizeof(t_stack));
		new_node->x = curr->x;
		new_node->next = NULL;
		if (prev != NULL)
			prev->next = new_node;
		else
			new_list = new_node;
		prev = new_node;
		curr = curr->next;
	}
	return (new_list);
}

int	start(t_group *group)
{
	t_stack	*temp;
	t_stack	*clone;
	int		start;

	clone = clone_list(group->a);
	temp = clone;
	sort_list(temp);
	start = temp->x;
	ft_free_stack(&clone);
	return (start);
}

int	end(t_group *group)
{
	t_stack	*temp;
	t_stack	*clone;
	int		end;

	clone = clone_list(group->a);
	temp = clone;
	sort_list(temp);
	end = 0;
	while (temp->next != NULL && end != group->chunk->chunk_size * 2)
	{
		end++;
		temp = temp->next;
	}
	end = temp->x;
	ft_free_stack(&clone);
	return (end);
}

void	send_pb(t_group *group, int top, int bottom)
{
	if (top <= bottom)
	{
		while (top-- != 0)
			rotate(&group->a, "ra");
		push(&group->b, &group->a, "pb");
	}
	else if (top > bottom)
	{
		while (bottom-- != 0)
			rev_rotate(&group->a, "rra");
		push(&group->b, &group->a, "pb");
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

int	midpoint(t_stack *a, int i)
{
	t_stack	*temp;
	t_stack	*clone;
	int		value;

	clone = clone_list(a);
	temp = clone;
	sort_list(temp);
	i = i / 2;
	while (i-- != 0 && temp->next != NULL)
		temp = temp->next;
	value = temp->x;
	ft_free_stack(&clone);
	return (value);
}


void	best_move(t_group *group, int start, int end)
{
	int		top;
	int		flag;

	group->chunk->i = numero_movi(group->a, end);
	group->chunk->md_pnt = midpoint(group->a, group->chunk->i);
	while (group->a && group->chunk->i-- != 0)
	{
		flag = 0;
		group->chunk->temp = (group->a);
		while (group->chunk->temp->next != NULL)
		{
			if ((group->chunk->temp->x >= start && group->chunk->temp->x <= end) && flag == 0)
			{
				top = group->chunk->temp->x;
				flag = 1;
			}
			if (group->chunk->temp->x >= start && group->chunk->temp->x <= end)
				group->chunk->bottom = group->chunk->temp->x;
			group->chunk->temp = group->chunk->temp->next;
		}
		send_pb(group, gv_i(group->a, top), (group->size_a - gv_i(group->a, group->chunk->bottom)));
		if (group->size_b > 1 && (group->b)->x < group->chunk->md_pnt)
			rotate(&group->b, "rb");
	}
}

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

void	chunk_midpoint(t_group *group)
{

}

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
		rotate(group->b, "rb");
		temp = temp->next;
	}
	

}

void	sort_back_a(t_group *group)
{
	push(&group->a, &group->b, "pa");
	group->size_b--;
	group->size_a++;
	while (group->size_b)
	{
		end_chunk_top(group);
		if (group->size_a == 1)
			find_best_friend(group);
		while ()
		{
			
		}
	}
}

void	sort_biggest(t_group *group)
{
	while (group->size_a != 0)
		best_move(group, start(group), end(group));
	add_to_buffer("");
	sort_back_a(group);
	chunk_midpoint(group);
}