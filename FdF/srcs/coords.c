/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 22:11:08 by rafasant          #+#    #+#             */
/*   Updated: 2025/01/06 22:16:35 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

int	adjust_z(t_bag *bag, t_wf *wf, int z)
{
	float	result;
	float	normalization_factor;
	int		zoom;

	zoom = wf->zoom;
	if (wf->zoom < 20)
		zoom = 20;
	normalization_factor = zoom / log(bag->max_z + 1.0);
	if (z >= 0)
		result = logf(z + 1.0f) * normalization_factor;
	else
		result = -logf(-z + 1.0f) * normalization_factor;
	return ((int)result);
}

t_coords	assign_coords(t_bag *bag, t_wf *wf, int x, int y)
{
	t_coords	coords;

	coords.x = x * wf->zoom - bag->axis_len * wf->zoom / 2;
	coords.y = y * wf->zoom - bag->ordinate_len * wf->zoom / 2;;
	coords.z = adjust_z(bag, wf, bag->map[y][x].altitude);
	coords.colour = bag->map[y][x].colour;
	if (wf->pers == 0)
		rotate_iso(&coords);
	rotate_x_axis(wf, &coords);
	rotate_y_axis(wf, &coords);
	rotate_z_axis(wf, &coords);
	coords.x = coords.x + wf->x;
	coords.y = coords.y + wf->y;
	return (coords);
}

void	set_dir(t_coords *dir, t_coords diff)
{
	dir->x = 1;
	if (diff.x < 0)
		dir->x = -1;
	dir->y = 1;
	if (diff.y < 0)
		dir->y = -1;
}
