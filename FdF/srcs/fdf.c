/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:05:54 by rafasant          #+#    #+#             */
/*   Updated: 2024/12/20 18:30:43 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	rotate_x_axis(t_bag *bag, t_wf *wf, t_coords *point)
{
	int	prev_y;
	int	prev_z;

	(void)bag;
	prev_y = point->y;
	prev_z = point->z;
	point->y = prev_y * cos(wf->x_angle) + prev_z * sin(wf->x_angle);
	point->z = -prev_y * sin(wf->x_angle) + prev_z * cos(wf->x_angle);

}

void	rotate_y_axis(t_bag *bag, t_wf *wf, t_coords *point)
{
	int	prev_x;
	int	prev_z;

	(void)bag;
	prev_x = point->x;
	prev_z = point->z;
	point->x = prev_x * cos(wf->y_angle) + prev_z * sin(wf->y_angle);
	point->z = -prev_x * sin(wf->y_angle) + prev_z * cos(wf->y_angle);

}

void	rotate_z_axis(t_bag *bag, t_wf *wf, t_coords *point)
{
	int	prev_x;
	int	prev_y;

	(void)bag;
	prev_x = point->x;
	prev_y = point->y;
	point->x = prev_x * cos(wf->z_angle) - prev_y * sin(wf->z_angle);
	point->y = prev_x * sin(wf->z_angle) + prev_y * cos(wf->z_angle);

}

void	rotate_iso(t_bag *bag, t_wf *wf, t_coords *point)
{
	int	prev_x;
	int	prev_y;

	(void)wf;
	(void)bag;
	prev_x = point->x;
	prev_y = point->y;
	point->x = (int)(sin(0.7853981634) * (prev_x - prev_y));
	point->y = (int)(cos(0.6154729074) * (sin(0.7853981634) * (prev_x + prev_y)) - sin(0.6154729074) * point->z);
}

int	adjust_z(t_bag *bag, t_wf *wf, int z)
{
	float	result;
	float	normalization_factor;

	normalization_factor = wf->zoom / log(bag->max_z + 1.0);
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
		rotate_iso(bag, wf, &coords);
	rotate_x_axis(bag, wf, &coords);
	rotate_y_axis(bag, wf, &coords);
	rotate_z_axis(bag, wf, &coords);
	coords.x = coords.x + wf->x;
	coords.y = coords.y + wf->y;
	return (coords);
}

// int	get_color(t_coords current, t_coords start, t_coords end, t_coords delta)
// {
// 	int		red;
// 	int		green;
// 	int		blue;
// 	double	percentage;

// 	if (current.colour == end.colour)
// 		return (current.colour);
// 	if (delta.x > delta.y)
// 		percentage = percent(start.x, end.x, current.x);
// 	else
// 		percentage = percent(start.y, end.y, current.y);
// 	red = get_li((start.colour >> 16) & 0xFF, (end.colour >> 16) & 0xFF,
// 			percentage);
// 	green = get_li((start.colour >> 8) & 0xFF, (end.colour >> 8) & 0xFF,
// 			percentage);
// 	blue = get_li(start.colour & 0xFF, end.colour & 0xFF, percentage);
// 	return ((red << 16) | (green << 8) | blue);
// }

void	set_dir(t_coords *dir, t_coords diff)
{
	dir->x = 1;
	if (diff.x < 0)
		dir->x = -1;
	dir->y = 1;
	if (diff.y < 0)
		dir->y = -1;
}

void	place_in_map(t_wf *wf, t_coords *point)
{
	point->x = point->x + wf->x;
	point->y = point->y + wf->y;
}

int	get_colour(t_coords curr, t_coords next, t_coords diff)
{
	int	colour;
	int	colour_diff;
	int	coords_diff;

	if (curr.colour == next.colour)
		return (0);
	colour_diff = next.colour - curr.colour;
	if (colour_diff < 0)
		
	else if (next.colour > curr.colour)
	coords_diff = diff.x;
	if (diff.x < diff.y)
		coords_diff = diff.y;
	
	colour = curr.colour + ;
	return (curr.colour);
}

//TO DO
// finish get_colour()
void	draw_line(t_bag *bag, t_wf *wf, t_coords curr, t_coords next)
{
	t_coords	diff;
	t_coords	dir;
	int			colour;
	int			margin[2];

	diff.x = next.x - curr.x;
	diff.y = next.y - curr.y;
	set_dir(&dir, diff);
	diff.x = abs(diff.x);
	diff.y = abs(diff.y);
	margin[0] = diff.x - diff.y;
	colour = get_colour(curr, next, diff);
	while ((curr.x != next.x || curr.y != next.y))
	{
		if (curr.x >= 0 && curr.y >= 0 && curr.x <= bag->mlx->width && curr.y <= bag->mlx->height)
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
		curr.colour += colour;
	}
}

void	create_wireframe(t_bag *bag, t_wf *wf)
{
	int	x;
	int	y;

	wf->canva->img = mlx_new_image(bag->mlx->mlx_ptr, bag->mlx->width, bag->mlx->height);
	wf->canva->addr = mlx_get_data_addr(wf->canva->img, &wf->canva->bits_per_pixel, &wf->canva->line_length, &wf->canva->endian);
	y = 0;
	while (y < bag->ordinate_len)
	{
		x = 0;
		while (x < bag->axis_len)
		{
			if (y + 1 < bag->ordinate_len)
				draw_line(bag, wf, assign_coords(bag, wf, x, y), assign_coords(bag, wf, x, y + 1));
			if (x + 1 < bag->axis_len)
				draw_line(bag, wf, assign_coords(bag, wf, x, y), assign_coords(bag, wf, x + 1, y));
			x++;
		}
		y++;
	}
}

int	mouse_press(int mouse_code, int x, int y, t_bag *bag)
{
	(void)x;
	(void)y;
	if (!bag->mod_wf)
		copy_og_wf(bag);
	else
		mlx_destroy_image(bag->mlx->mlx_ptr, bag->mod_wf->canva->img);
	if (mouse_code == ZOOM_IN)
		bag->mod_wf->zoom = bag->mod_wf->zoom + 10;
	else if (mouse_code == ZOOM_OUT)
		bag->mod_wf->zoom = bag->mod_wf->zoom - 10;
	create_wireframe(bag, bag->mod_wf);
	mlx_put_image_to_window(bag->mlx->mlx_ptr, bag->mlx->win_ptr, bag->mod_wf->canva->img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_bag	*bag;

	if (argc != 2)
		return (1);
	bag = create_bag(argv[1]);
	bag->mlx->mlx_ptr = mlx_init();
	if (!bag->mlx->mlx_ptr)
		deallocate(bag);
	bag->mlx->win_ptr = mlx_new_window(bag->mlx->mlx_ptr, bag->mlx->width, bag->mlx->height, "Hello world!");
	if (!bag->mlx->win_ptr)
		deallocate(bag);
	create_wireframe(bag, bag->og_wf);
	mlx_put_image_to_window(bag->mlx->mlx_ptr, bag->mlx->win_ptr, bag->og_wf->canva->img, 0, 0);
	mlx_hook(bag->mlx->win_ptr, 2, (1L << 0), hooks, bag);
	mlx_hook(bag->mlx->win_ptr, 4, (1L << 2), mouse_press, bag);
	mlx_hook(bag->mlx->win_ptr, 17, (1L << 2), close_window, bag);
	mlx_loop(bag->mlx->mlx_ptr);
	return (0);
}
