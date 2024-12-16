/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:17:47 by rafasant          #+#    #+#             */
/*   Updated: 2024/12/16 18:03:11 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

// int	mouse_hooks(int mouse_code, t_bag *bag)
// {
// 	if (mouse_code == SCROLL_UP && bag->og_wf->zoom < 100)
// 		bag->og_wf->zoom = bag->og_wf->zoom + 10;
// 	else if (mouse_code == SCROLL_DOWN && bag->og_wf->zoom > 0)
// 		bag->og_wf->zoom = bag->og_wf->zoom - 10;
// 	else if (mouse_code == KEY_S)
// 	{
// 		if (bag->og_wf->zoom > 0)
// 			bag->og_wf->zoom = bag->og_wf->zoom - 10;
// 	}
// 	else if (mouse_code == KEY_D)
// 	{

// 	}
// }

int	close_window(t_bag *bag)
{
	mlx_destroy_image(bag->mlx->mlx_ptr, bag->og_wf->canva->img);
	mlx_destroy_window(bag->mlx->mlx_ptr, bag->mlx->win_ptr);
	mlx_destroy_display(bag->mlx->mlx_ptr);
	deallocate(bag);
	return (0);
}

void	reset_screen(t_bag *bag)
{
	if (bag->mod_wf)
		mlx_destroy_image(bag->mlx->mlx_ptr, bag->mod_wf->canva->img);
	mlx_put_image_to_window(bag->mlx->mlx_ptr, bag->mlx->win_ptr, bag->og_wf->canva->img, 0, 0);
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
}

//TODO
// maybe limit the map to the visible window
// if ((point_coordinates) > 0 && < width/height)
int	hooks(int keycode, t_bag *bag)
{
	if (keycode == ESC)
		close_window(bag);
	if (keycode == RESET)
		return (reset_screen(bag), 0);
	if (!bag->mod_wf)
	{
		ft_printf("helo\n");
		copy_og_wf(bag);
	}
	else
		mlx_destroy_image(bag->mlx->mlx_ptr, bag->mod_wf->canva->img);
	if (keycode == MOVE_UP && bag->mod_wf->y > INT_MIN)
	{
		ft_printf("helo\n");
		bag->mod_wf->y -= 100;
	}
	else if (keycode == MOVE_DOWN && bag->mod_wf->y < INT_MAX)
		bag->mod_wf->y += 100;
	else if (keycode == MOVE_LEFT && bag->mod_wf->x > INT_MIN)
		bag->mod_wf->x -= 100;
	else if (keycode == MOVE_RIGHT && bag->mod_wf->x < INT_MAX)
		bag->mod_wf->x += 100;
	else
		return (0);
	create_wireframe(bag, bag->mod_wf);
	mlx_put_image_to_window(bag->mlx->mlx_ptr, bag->mlx->win_ptr, bag->mod_wf->canva->img, 0, 0);
	return (0);
}