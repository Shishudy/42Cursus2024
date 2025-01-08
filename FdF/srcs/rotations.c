/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 22:10:11 by rafasant          #+#    #+#             */
/*   Updated: 2025/01/08 16:51:02 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

void	rotate_x_axis(t_wf *wf, t_coords *point)
{
	int	prev_y;
	int	prev_z;

	prev_y = point->y;
	prev_z = point->z;
	point->y = prev_y * cos(wf->x_angle) + prev_z * sin(wf->x_angle);
	point->z = -prev_y * sin(wf->x_angle) + prev_z * cos(wf->x_angle);
}

void	rotate_y_axis(t_wf *wf, t_coords *point)
{
	int	prev_x;
	int	prev_z;

	prev_x = point->x;
	prev_z = point->z;
	point->x = prev_x * cos(wf->y_angle) + prev_z * sin(wf->y_angle);
	point->z = -prev_x * sin(wf->y_angle) + prev_z * cos(wf->y_angle);
}

void	rotate_z_axis(t_wf *wf, t_coords *point)
{
	int	prev_x;
	int	prev_y;

	prev_x = point->x;
	prev_y = point->y;
	point->x = prev_x * cos(wf->z_angle) - prev_y * sin(wf->z_angle);
	point->y = prev_x * sin(wf->z_angle) + prev_y * cos(wf->z_angle);
}

void	rotate_iso(t_coords *point)
{
	int	prev_x;
	int	prev_y;

	prev_x = point->x;
	prev_y = point->y;
	point->x = (int)(sin(0.7853981634) * (prev_x - prev_y));
	point->y = (int)(cos(0.6154729074) * (sin(0.7853981634) * \
	(prev_x + prev_y)) - sin(0.6154729074) * point->z);
}
