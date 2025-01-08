/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:53:19 by rafasant          #+#    #+#             */
/*   Updated: 2025/01/08 15:54:26 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

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
