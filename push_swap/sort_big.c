/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:50:55 by rafasant          #+#    #+#             */
/*   Updated: 2024/09/16 20:48:14 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_list(t_stack **root)
{
	t_stack	*current;
	t_stack	*index;
	int		temp;

	if (!*root)
		return ;
	temp = 0;
	index = NULL;
	current = *root;
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

t_stack	*clone_list(t_stack **root)
{
	t_stack	*new_list;
	t_stack	*new_node;
	t_stack	*prev;
	t_stack	*curr;

	prev = NULL;
	new_list = NULL;
	curr = *root;
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

int	start(t_stack **a)
{
	t_stack	*temp;
	t_stack	*clone;
	int		start;

	clone = clone_list(a);
	temp = clone;
	sort_list(&temp);
	start = temp->x;
	ft_free_stack(&clone);
	return (start);
}

int	end(t_stack **a)
{
	t_stack	*temp;
	t_stack	*clone;
	int		end;

	clone = clone_list(a);
	temp = clone;
	sort_list(&temp);
	end = 0;
	while (temp->next != NULL && end != 24)
	{
		end++;
		temp = temp->next;
	}
	end = temp->x;
	ft_free_stack(&clone);
	return (end);
}

int	cnt_rec(t_stack *root)
{
	if (root == NULL)
		return (0);
	return (1 + cnt_rec(root->next));
}

void	send_pb(t_stack **a, t_stack **b, int top, int bottom)
{
	if (top <= bottom)
	{
		while (top-- != 0)
			rotate(a, "ra");
		push(b, a, "pb");
	}
	else if (top > bottom)
	{
		while (bottom-- != 0)
			rev_rotate(a, "rra");
		push(b, a, "pb");
	}
}

int	gv_i(t_stack **a, int element)
{
	t_stack	*temp;
	int		index_a;

	temp = (*a);
	index_a = 0;
	while (temp->next != NULL && element != temp->x)
	{
		index_a++;
		temp = temp->next;
	}
	return (index_a);
}

int	numero_movi(t_stack **a, int end)
{
	t_stack	*temp;
	t_stack	*clone;
	int		i;

	clone = clone_list(a);
	temp = clone;
	sort_list(&temp);
	i = 1;
	while (temp->next != NULL && temp->x != end)
	{
		i++;
		temp = temp->next;
	}
	ft_free_stack(&clone);
	return (i);
}

int	midpoint(t_stack **a, int i)
{
	t_stack	*temp;
	t_stack	*clone;
	int		value;

	clone = clone_list(a);
	temp = clone;
	sort_list(&temp);
	i = i / 2;
	while (i-- != 0 && temp->next != NULL)
		temp = temp->next;
	value = temp->x;
	ft_free_stack(&clone);
	return (value);
}


void	best_move(t_stack **a, t_stack **b, int start, int end)
{
	t_chunk	use;
	int		top;
	int		flag;

	use.i = numero_movi(a, end);
	use.md_pnt = midpoint(a, use.i);
	while (*a && use.i-- != 0)
	{
		flag = 0;
		use.temp = (*a);
		while (use.temp->next != NULL)
		{
			if ((use.temp->x >= start && use.temp->x <= end) && flag == 0)
			{
				top = use.temp->x;
				flag = 1;
			}
			if (use.temp->x >= start && use.temp->x <= end)
				use.bottom = use.temp->x;
			use.temp = use.temp->next;
		}
		send_pb(a, b, gv_i(a, top), (cnt_rec(*a) - gv_i(a, use.bottom)));
		if (cnt_rec(*b) > 1 && (*b)->x < use.md_pnt)
			rotate(b, "rb");
	}
}

void	sort_biggest(t_group *group)
{
	// t_stack	*temp;

	while (group->size_a != 0)
		best_move(&group->a, &group->b, start(&group->a), end(&group->a));
	// while (cnt_rec(*b) > 30)
	// {
	// 	temp = (*b);
	// 	while (temp->next != NULL)
	// 		temp = temp->next;
	// 	if ((*b)->x > temp->x)
	// 		send_top_b(a, b);
	// 	else if ((*b)->x < temp->x)
	// 		send_bot_b(a, b);
	// }
	// send_rest(a, b);
}