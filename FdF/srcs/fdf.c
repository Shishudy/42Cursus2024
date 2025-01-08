/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:05:54 by rafasant          #+#    #+#             */
/*   Updated: 2025/01/08 16:36:54 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

void	hooks_loop(t_bag *bag)
{
	mlx_hook(bag->mlx->win_ptr, 2, (1L << 0), hooks, bag);
	mlx_hook(bag->mlx->win_ptr, 4, (1L << 2), mouse_hooks, bag);
	mlx_hook(bag->mlx->win_ptr, 17, (1L << 2), close_window, bag);
	mlx_loop_hook(bag->mlx->mlx_ptr, draw_wireframe, bag);
}

int	main(int argc, char **argv)
{
	t_bag	*bag;

	if (argc != 2)
		return (1);
	bag = create_bag(argv[1]);
	create_wireframe(bag, bag->og_wf);
	hooks_loop(bag);
	mlx_loop(bag->mlx->mlx_ptr);
	return (0);
}
