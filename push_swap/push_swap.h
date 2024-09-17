/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:01:51 by rafasant          #+#    #+#             */
/*   Updated: 2024/09/17 23:29:26 by rafasant         ###   ########.fr       */
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
	t_stack			*temp;
	t_stack			*last;
	int				chunk_size;
	//int				chunks;
	int				n;
	int				i;
	int				md_pnt;
	int				bottom;
	int				chunk_size;
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


int		ft_stack_size(t_stack *lst);
int		list_sorted(t_stack **stack);
void	ft_addtolist(t_group *group, int x);
int		split_atoi(t_group *group, char **argv);
void	check_argv(t_group *group, char **argv);

void	deallocate(t_group *group, int message);
void	push(t_stack **send_to, t_stack **send_from, char *move);
void	swap(t_stack **stack, char *move);
void	rotate(t_stack **stack, char *move);
void	rev_rotate(t_stack **stack, char *move);
void	ft_free_stack(t_stack **stack);
void	add_to_buffer(char	*move);

void	sort_biggest(t_group *group);

#endif