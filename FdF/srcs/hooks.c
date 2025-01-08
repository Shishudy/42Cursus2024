/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:17:47 by rafasant          #+#    #+#             */
/*   Updated: 2025/01/08 15:54:22 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

int	mouse_hooks(int mouse_code, int x, int y, t_bag *bag)
{
	(void)x;
	(void)y;
	if (!bag->mod_wf)
		copy_og_wf(bag);
	else
	{
		mlx_destroy_image(bag->mlx->mlx_ptr, bag->mod_wf->canva->img);
		new_image(bag);
	}
	if (mouse_code == ZOOM_IN)
		bag->mod_wf->zoom++;
	else if (mouse_code == ZOOM_OUT)
		bag->mod_wf->zoom--;
	if (bag->mod_wf->zoom < 1)
		bag->mod_wf->zoom = 1;
	return (0);
}

void	keyboard_hooks(t_bag *bag, int keycode)
{
	if (keycode == MOVE_UP && bag->mod_wf->y > INT_MIN)
		bag->mod_wf->y -= 20;
	else if (keycode == MOVE_DOWN && bag->mod_wf->y < INT_MAX)
		bag->mod_wf->y += 20;
	else if (keycode == MOVE_LEFT && bag->mod_wf->x > INT_MIN)
		bag->mod_wf->x -= 20;
	else if (keycode == MOVE_RIGHT && bag->mod_wf->x < INT_MAX)
		bag->mod_wf->x += 20;
	else if (keycode == ROTATE_UP)
		bag->mod_wf->x_angle -= 0.05;
	else if (keycode == ROTATE_DOWN)
		bag->mod_wf->x_angle += 0.05;
	else if (keycode == ROTATE_LEFT)
		bag->mod_wf->y_angle -= 0.05;
	else if (keycode == ROTATE_RIGHT)
		bag->mod_wf->y_angle += 0.05;
	else if (keycode == ROTATE_Z_LEFT)
		bag->mod_wf->z_angle -= 0.05;
	else if (keycode == ROTATE_Z_RIGHT)
		bag->mod_wf->z_angle += 0.05;
	else if (keycode == ISOMETRIC || keycode == PARALLEL)
		change_projection(bag, keycode);
}

int	hooks(int keycode, t_bag *bag)
{
	if (!valid_keycode(bag, keycode))
		return (0);
	if (keycode == ESC)
		close_window(bag);
	else if (keycode == RESET)
		return (reset_screen(bag), 0);
	if (!bag->mod_wf)
		copy_og_wf(bag);
	else
	{
		mlx_destroy_image(bag->mlx->mlx_ptr, bag->mod_wf->canva->img);
		new_image(bag);
	}
	keyboard_hooks(bag, keycode);
	return (0);
}
