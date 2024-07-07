/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:01:51 by rafasant          #+#    #+#             */
/*   Updated: 2024/07/07 12:54:35 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

// # define PA 0
// # define PB 1
// # define SA 2
// # define SB 3
// # define SS 4
// # define RA 5
// # define RB 6
// # define RR 7
// # define RRA 8
// # define RRB 9
// # define RRR 10

typedef struct s_stack
{
	int		x;
	struct s_stack	*next;
}				t_stack;

int		split_atoi(char **argv, t_stack **a);
void	deallocate(t_stack **stack, int message);
void	check_argv(char **argv, t_stack **a);
int		list_sorted(t_stack **stack);
void	push(t_stack **send_to, t_stack **send_from, char *move);
void	swap(t_stack **list1, t_stack **list2, char *move);
void	rotate(t_stack **list1, t_stack **list2, char *move);
void	rev_rotate(t_stack **list1, t_stack **list2, char *move);

#endif