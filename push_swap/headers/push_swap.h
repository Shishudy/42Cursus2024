/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:01:51 by rafasant          #+#    #+#             */
/*   Updated: 2024/10/03 18:47:20 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

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

typedef struct s_group
{
	struct s_stack	*a;
	struct s_stack	*b;
	struct s_chunk	*chunk;
	int				sign;
	long int		x;
	int				control;
	int				size_a;
	int				size_b;
}					t_group;

/* init_group.c */
void	chunk_calculator(t_group *group);
t_group	*init_group(char **argv);

/* check_args.c */
int		ft_stack_size(t_stack *lst);
void	ft_addtolist(t_group *group, int x);
void	split_atoi(t_group *group, char **argv);
void	check_argv(t_group *group, char **argv);

/* sort_utils1.c */
void	sort_list(t_stack *root);
t_stack	*clone_list(t_stack *root);
int		list_sorted(t_stack *stack);
int		calculate_cost(t_stack *stack, int stack_size, int target, int flag);
void	push_cheapest_a(t_group *group, int cost);
void	push_cheapest_b(t_group *group, int cost);
int		find_value(t_stack *stack, int flag);

/* sort_utils2.c */
int		cnt_rec(t_stack *stack, int min, int max, int value);
int		find_cheapest(t_stack *stack, int min, int max, int size);
void	start_chunk(t_group *group);
void	end_chunk(t_group *group);
void	midpoint(t_group *group, t_stack *stack, int start, int end);

/* error.c */
void	ft_free_stack(t_stack **stack);
void	deallocate(t_group *group, int message);

/* moves.c */
void	add_to_buffer(char	*move);
void	push(t_stack **send_to, t_stack **send_from, char *move, \
t_group *group);
void	swap(t_stack **stack, char *move);
void	rotate(t_stack **stack, char *move);
void	rev_rotate(t_stack **stack, char *move);

/* sort_small.c */
void	sort_3(t_group *group);
void	re_sort_3(t_group *group);
void	sort_5(t_group *group);
void	sort_less_10(t_group *group);

/* sort_big.c */
void	sort_to_b(t_group *group);

#endif