/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:25:27 by rafasant          #+#    #+#             */
/*   Updated: 2024/09/16 19:53:09 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_calculator(t_group *group)
{
	group->chunk->chunks = ft_stack_size(group->a) / 10;
	group->chunk->chunk_size = ft_stack_size(group->a) / group->chunk->chunks;
	//intervalo de valores dentro da chunk
}