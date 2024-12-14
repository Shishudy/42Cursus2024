/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:05:54 by rafasant          #+#    #+#             */
/*   Updated: 2024/12/14 20:25:53 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// int	mouse_hook(int mouse, t_bag *bag)
// {
// 	ft_printf("%d\n", mouse);
// 	(void)bag;
// 	return (0);
// }

void	apply_rotation(t_coords *point, double angle)
{
	double	prev_x;
	double	prev_y;

	prev_x = point->x;
	prev_y = point->y;
	point->x = prev_x * cos(angle) - prev_y * sin(angle);
	point->y = prev_x * sin(angle) + prev_y * cos(angle);
}

void	rotate_iso(t_bag *bag, t_coords *point)
{
	int	prev_x;
	int	prev_y;

	(void)bag;
	prev_x = point->x - bag->axis_len * bag->og_wf->zoom / 2;
	prev_y = point->y - bag->ordinate_len * bag->og_wf->zoom / 2;
	point->x = (int)(sin(0.9999) * (prev_x - prev_y));
	point->y = (int)(cos(0.6154729074) * (sin(0.7853981634) * (prev_x + prev_y)) - sin(0.6154729074) * point->z);
	// point->x = (int)(sin(0.7853981634) * (prev_x - prev_y));
	// point->y = (int)(cos(0.6154729074) * (sin(0.7853981634) * (prev_x + prev_y)) - sin(0.6154729074) * point->z);
}

t_coords	assign_coords(t_bag *bag, int x, int y)
{
	t_coords	coords;

	coords.x = x;
	coords.y = y;
	coords.z = bag->map[y][x].altitude;
	coords.colour = bag->map[y][x].colour;
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

int	get_colour(t_coords curr, t_coords next)
{
	int	colour;
	static int	colour_diff;

	if (colour_diff == 0 && curr.colour != next.colour)
		colour_diff = 1;
	colour = next.colour - curr.colour;
	return (0xFFFFFF);
}

void	place_in_map(t_bag *bag, t_coords *point)
{
	point->x = point->x + bag->og_wf->x;
	point->y = point->y + bag->og_wf->y;
}

void	apply_zoom(t_bag *bag, t_coords *point)
{
	point->x = point->x * bag->og_wf->zoom;
	point->y = point->y * bag->og_wf->zoom;
	point->z = point->z * bag->og_wf->zoom;
}

//TO DO
// finish get_colour()
// replace rotate_iso to receive angle given by user
void	draw_line(t_bag *bag, t_coords curr, t_coords next)
{
	t_coords	diff;
	t_coords	dir;
	int			margin[2];

	apply_zoom(bag, &curr);
	apply_zoom(bag, &next);
	rotate_iso(bag, &curr);
	rotate_iso(bag, &next);
	place_in_map(bag, &curr);
	place_in_map(bag, &next);
	// apply_rotation(bag, &curr, 0.5235987756);
	// apply_rotation(bag, &next, 0.5235987756);
	diff.x = next.x - curr.x;
	diff.y = next.y - curr.y;
	set_dir(&dir, diff);
	diff.x = abs(diff.x);
	diff.y = abs(diff.y);
	margin[0] = diff.x - diff.y;
	while ((curr.x != next.x || curr.y != next.y))
	{
		if (curr.x >= 0 && curr.y >= 0 && curr.x <= bag->mlx->width && curr.y <= bag->mlx->height)
			my_mlx_pixel_put(bag->og_wf->canva, curr.x, curr.y, get_colour(curr, next));
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

void	create_wireframe(t_bag *bag)
{
	int	x;
	int	y;

	bag->og_wf->zoom = 30;
	bag->og_wf->canva->img = mlx_new_image(bag->mlx->mlx_ptr, bag->mlx->width, bag->mlx->height);
	bag->og_wf->canva->addr = mlx_get_data_addr(bag->og_wf->canva->img, &bag->og_wf->canva->bits_per_pixel, &bag->og_wf->canva->line_length, &bag->og_wf->canva->endian);
	y = 0;
	while (y < bag->ordinate_len)
	{
		x = 0;
		while (x < bag->axis_len)
		{
			if (y + 1 < bag->ordinate_len)
				draw_line(bag, assign_coords(bag, x, y), assign_coords(bag, x, y + 1));
			if (x + 1 < bag->axis_len)
				draw_line(bag, assign_coords(bag, x, y), assign_coords(bag, x + 1, y));
			x++;
		}
		y++;
	}
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
	create_wireframe(bag);
	mlx_put_image_to_window(bag->mlx->mlx_ptr, bag->mlx->win_ptr, bag->og_wf->canva->img, 0, 0);
	mlx_hook(bag->mlx->win_ptr, 2, (1L << 0), hooks, bag);
	mlx_hook(bag->mlx->win_ptr, 17, (1L << 2), close_window, bag);
	//mlx_mouse_hook(bag->win->win, mouse_hook, bag);
	mlx_loop(bag->mlx->mlx_ptr);
	return (0);
}
