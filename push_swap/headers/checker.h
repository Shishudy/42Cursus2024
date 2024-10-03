/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:55:17 by rafasant          #+#    #+#             */
/*   Updated: 2024/10/03 16:48:16 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"

typedef struct s_stack
{
	int				x;
	struct s_stack	*next;
}					t_stack;
typedef struct s_group
{
	struct s_stack	*a;
	struct s_stack	*b;
	int				sign;
	long int		x;
	int				size_a;
	int				size_b;
}					t_group;

// checker.c
void	parse_move_combo(t_group *group, char *move);
void	parse_move(t_group *group, char *move);

// check_args_bonus.c
int		ft_stack_size(t_stack *lst);
void	ft_addtolist(t_group *group, int x);
void	split_atoi(t_group *group, char **argv);
void	check_argv(t_group *group, char **argv);
t_group	*init_group(char **argv);

// moves_bonus.c
void	push(t_stack **send_to, t_stack **send_from, char *move, \
t_group *group);
void	swap(t_stack **stack);
void	rotate(t_stack **stack);
void	rev_rotate(t_stack **stack);

// error_bonus.c
int		list_sorted(t_stack *stack);
void	ft_free_stack(t_stack **stack);
void	deallocate(t_group *group, int message);

#endif