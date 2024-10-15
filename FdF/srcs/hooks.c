/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:17:47 by rafasant          #+#    #+#             */
/*   Updated: 2024/10/15 19:09:08 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

int	close_window(t_bag *bag)
{
	mlx_destroy_window(bag->mlx->mlx_ptr, bag->mlx->win_ptr);
	mlx_destroy_display(bag->mlx->mlx_ptr);
	deallocate(bag);
	return (0);
}

int	hooks(int keycode, t_bag *bag)
{
	if (keycode == KEY_ESC)
		close_window(bag);
	return (0);
}