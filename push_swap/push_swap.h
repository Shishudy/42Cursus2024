/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:01:51 by rafasant          #+#    #+#             */
/*   Updated: 2024/09/11 22:27:47 by rafasant         ###   ########.fr       */
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

typedef struct s_moves
{
	char			*move;
	struct s_moves	*next;
}					t_moves;

typedef	struct s_group
{
	struct	s_stack *a;
	struct	s_stack *b;
	struct	s_moves	*moves;
}					t_group;


int		split_atoi(char **argv, t_stack **a);
void	deallocate(t_group *group, int message);
void	deallocate2(t_stack **stack, int message);
void	check_argv(char **argv, t_stack **a);
int		ft_stack_size(t_stack *lst);
int		list_sorted(t_stack **stack);
void	ft_addtolist(t_stack **a, int x);
void	push(t_stack **send_to, t_stack **send_from, char *move);
void	swap(t_stack **stack, char *move);
void	rotate(t_stack **stack, char *move);
void	rev_rotate(t_stack **stack, char *move);
void	put_move_array(char **array_moves, char *move, int n_move);
void	ft_free(t_group **group);
void	ft_free_stack(t_stack **stack);

#endif