/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 22:09:18 by rafasant          #+#    #+#             */
/*   Updated: 2025/01/06 22:15:37 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_line(t_bag *bag, t_wf *wf, t_coords curr, t_coords next)
{
	t_coords	diff;
	t_coords	dir;
	int			margin[2];

	diff.x = next.x - curr.x;
	diff.y = next.y - curr.y;
	set_dir(&dir, diff);
	diff.x = abs(diff.x);
	diff.y = abs(diff.y);
	margin[0] = diff.x - diff.y;
	while ((curr.x != next.x || curr.y != next.y))
	{
		if (curr.x >= 0 && curr.y >= 0 && curr.x <= bag->mlx->width && \
		curr.y <= bag->mlx->height)
			my_mlx_pixel_put(wf->canva, curr.x, curr.y, curr.colour);
		margin[1] = margin[0];
		if ((margin[1]) > -diff.y)
		{
			margin[0] -= diff.y;
			curr.x += dir.x;
		}
		if (margin[1] < diff.x)
		{
			margin[0] += diff.x;
			curr.y += dir.y;
		}
	}
}

void	create_wireframe(t_bag *bag, t_wf *wf)
{
	int			x;
	int			y;
	t_coords	start;

	y = 0;
	while (y < bag->ordinate_len)
	{
		x = 0;
		while (x < bag->axis_len)
		{
			start = assign_coords(bag, wf, x, y);
			my_mlx_pixel_put(wf->canva, start.x, start.y, start.colour);
			if (y + 1 < bag->ordinate_len)
				draw_line(bag, wf, assign_coords(bag, wf, x, y), \
				assign_coords(bag, wf, x, y + 1));
			if (x + 1 < bag->axis_len)
				draw_line(bag, wf, assign_coords(bag, wf, x, y), \
				assign_coords(bag, wf, x + 1, y));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(bag->mlx->mlx_ptr, bag->mlx->win_ptr, \
	wf->canva->img, 0, 0);
}

int	draw_wireframe(t_bag *bag)
{
	if (bag->mod_wf)
		create_wireframe(bag, bag->mod_wf);
	else
		create_wireframe(bag, bag->og_wf);
	return (0);
}