/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:17:47 by rafasant          #+#    #+#             */
/*   Updated: 2025/01/06 22:08:48 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

int	close_window(t_bag *bag)
{
	mlx_destroy_image(bag->mlx->mlx_ptr, bag->og_wf->canva->img);
	if (bag->mod_wf)
		mlx_destroy_image(bag->mlx->mlx_ptr, bag->mod_wf->canva->img);
	mlx_destroy_window(bag->mlx->mlx_ptr, bag->mlx->win_ptr);
	mlx_destroy_display(bag->mlx->mlx_ptr);
	deallocate(bag);
	return (0);
}

void	reset_screen(t_bag *bag)
{
	if (!bag->mod_wf)
		return ;
	mlx_destroy_image(bag->mlx->mlx_ptr, bag->mod_wf->canva->img);
	free(bag->mod_wf->canva);
	free(bag->mod_wf);
	bag->mod_wf = NULL;
}

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

void	copy_og_wf(t_bag *bag)
{
	bag->mod_wf = malloc(sizeof(t_wf));
	if (!bag->mod_wf)
		deallocate(bag);
	bag->mod_wf->canva = malloc(sizeof(t_data));
	if (!bag->mod_wf->canva)
		deallocate(bag);
	bag->mod_wf->x = bag->og_wf->x;
	bag->mod_wf->y = bag->og_wf->y;
	bag->mod_wf->zoom = bag->og_wf->zoom;
	bag->mod_wf->x_angle = bag->og_wf->x_angle;
	bag->mod_wf->y_angle = bag->og_wf->y_angle;
	bag->mod_wf->z_angle = bag->og_wf->z_angle;
	bag->mod_wf->pers = bag->og_wf->pers;
	new_image(bag);
}

int	valid_keycode(t_bag *bag, int keycode)
{
	(void)bag;
	if (keycode == ESC || keycode == RESET || keycode == MOVE_UP \
	||keycode == MOVE_DOWN || keycode == MOVE_LEFT || keycode == MOVE_RIGHT \
	|| keycode == ROTATE_UP || keycode == ROTATE_DOWN \
	|| keycode == ROTATE_LEFT || keycode == ROTATE_RIGHT \
	|| keycode == ROTATE_Z_LEFT || keycode == ROTATE_Z_RIGHT \
	|| keycode == PARALLEL || keycode == ISOMETRIC \
	|| keycode == ZOOM_IN || keycode == ZOOM_OUT)
		return (1);
	// if ((keycode == MOVE_UP && bag->mod_wf->y > INT_MIN) || \
	// (keycode == MOVE_DOWN && bag->mod_wf->y < INT_MAX) || \
	// (keycode == MOVE_LEFT && bag->mod_wf->x > INT_MIN) || \
	// (keycode == MOVE_RIGHT && bag->mod_wf->x < INT_MAX))
	// 	return (1);
	return (0);
}

void	change_projection(t_bag *bag, int keycode)
{
	if (keycode == PARALLEL)
		bag->mod_wf->pers = 1;
	else if (keycode == ISOMETRIC)
		bag->mod_wf->pers = 0;
	bag->mod_wf->x_angle = bag->og_wf->x_angle;
	bag->mod_wf->y_angle = bag->og_wf->y_angle;
	bag->mod_wf->z_angle = bag->og_wf->z_angle;
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

void	new_image(t_bag *bag)
{
	bag->mod_wf->canva->img = mlx_new_image(bag->mlx->mlx_ptr, bag->mlx->width, bag->mlx->height);
	if (!bag->mod_wf->canva->img)
		deallocate(bag);
	bag->mod_wf->canva->addr = mlx_get_data_addr(bag->mod_wf->canva->img, &bag->mod_wf->canva->bits_per_pixel, &bag->mod_wf->canva->line_length, &bag->mod_wf->canva->endian);
	if (!bag->mod_wf->canva->addr)
		deallocate(bag);
}

//TODO
// maybe limit the map to the visible window
// if ((point_coordinates) > 0 && < width/height)
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
