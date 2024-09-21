/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:01:51 by rafasant          #+#    #+#             */
/*   Updated: 2024/09/21 01:35:41 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				x;
	struct s_stack	*next;
}					t_stack;

typedef struct s_chunk
{
	int				start;
	int				end;
	int				chunk_size;
	int				chunks;
	int				midpoint;
}					t_chunk;

typedef	struct s_bf
{
	int				end_chunk;
	int				control;
	int				index_a;
	int				cost;

}					t_bf;


typedef	struct s_group
{
	struct	s_stack *a;
	struct	s_stack *b;
	struct	s_chunk	*chunk;
	struct	s_bf	*bf;
	int				size_a;
	int				size_b;
}					t_group;

/* init_group.c */
void	chunk_calculator(t_group *group);
t_group	*init_group(char **argv);

/* checkar_argv.c */
int		ft_stack_size(t_stack *lst);
int		list_sorted(t_stack **stack);
void	ft_addtolist(t_group *group, int x);
int		split_atoi(t_group *group, char **argv);
void	check_argv(t_group *group, char **argv);

/* sort_utils1.c */
void	sort_list(t_stack *root);
t_stack	*clone_list(t_stack *root);
int		calculate_cost(t_stack *stack, int stack_size, int target, int flag);
void	push_cheapest(t_group *group, int cost);
int		find_value(t_group *group, int flag);

/* sort_utils2.c */

void	push_back_a(t_group *group);

/* error.c */
void	ft_free_stack(t_stack **stack);
void	deallocate(t_group *group, int message);

/* moves.c */
void	push(t_stack **send_to, t_stack **send_from, char *move, t_group *group);
void	swap(t_stack **stack, char *move);
void	rotate(t_stack **stack, char *move);
void	rev_rotate(t_stack **stack, char *move);
void	add_to_buffer(char	*move);

/* sort_small.c */
void	sort_3(t_group *group);
void	sort_5(t_group *group);

/* sort_big.c */
void	sort_biggest(t_group *group);
void	sort_to_b(t_group *group);

#endif