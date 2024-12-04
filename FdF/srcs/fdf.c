/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:05:54 by rafasant          #+#    #+#             */
/*   Updated: 2024/12/04 20:03:32 by rafasant         ###   ########.fr       */
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

void	apply_rotation(t_bag *bag, t_coords *point, double angle)
{
	double	prev_x;
	double	prev_y;

	prev_x = point->x;
	prev_y = point->y;
	point->x = prev_x * cos(angle) - prev_y * sin(angle);
	point->y = prev_x * sin(angle) + prev_y * cos(angle);
	if ((int)point->x < 0)
		point->x = 0;
	if ((int)point->y < 0)
		point->y = 0;
	if ((int)point->x > bag->mlx->width)
		point->x = bag->mlx->width;
	if ((int)point->y > bag->mlx->height)
		point->y = bag->mlx->height;
}

void	rotate_iso(t_bag *bag, t_coords *point)
{
	double	prev_x;
	double	prev_y;

	prev_x = point->x;
	prev_y = point->y;
	point->x = (sin(0.7853981634) * (point->x - point->y));
	point->y = (cos(0.6154729074) * (sin(0.7853981634) * (prev_x + prev_y)) - sin(0.6154729074) * point->z);
	if ((int)point->x < 0)
		point->x = 0;
	if ((int)point->y < 0)
		point->y = 0;
	if ((int)point->x > bag->mlx->width)
		point->x = bag->mlx->width;
	if ((int)point->y > bag->mlx->height)
		point->y = bag->mlx->height;
}

t_coords	assign_coords(t_bag *bag, int x, int y, int zoom)
{
	t_coords	coords;

	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	coords.x = x * zoom + (bag->og_wf->x - (bag->axis_len * zoom / 2));
	coords.y = y * zoom + (bag->og_wf->y - (bag->ordinate_len * zoom / 2));
	coords.z = bag->map[y][x].altitude * zoom;
	coords.colour = bag->map[y][x].colour;
	return (coords);
}

int	colour_diff(t_coords prev, t_coords curr, int step)
{
	int	colour;

	colour = curr.colour - prev.colour;
	colour = colour / step;
	return (colour);
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

void	draw_line(t_bag *bag, t_coords prev, t_coords curr)
{
	double	diff_y;
	double	diff_x;
	double	step;

	rotate_iso(bag, &prev);
	rotate_iso(bag, &curr);
	// apply_rotation(bag, &prev, 0.5235987756);
	// apply_rotation(bag, &curr, 0.5235987756);
	diff_x = curr.x - prev.x;
	diff_y = curr.y - prev.y;
	if (fabs(diff_x) > fabs(diff_y))
		step = fabs(diff_x);
	else
		step = fabs(diff_y);
	diff_x = diff_x / step;
	diff_y = diff_y / step;
	int colour = (curr.colour - prev.colour) / step;
	while ((int)(prev.x - curr.x) || (int)(prev.y - curr.y))
	{
		if (prev.colour != 16777215)
			printf("Colour: %d\n", prev.colour);
		my_mlx_pixel_put(bag->og_wf->canva, prev.x, prev.y, prev.colour);
		prev.colour = prev.colour + colour;
		prev.x = prev.x + diff_x;
		prev.y = prev.y + diff_y;
	}
	my_mlx_pixel_put(bag->og_wf->canva, prev.x, prev.y, prev.colour);
}

// int	get_zoom(t_bag *bag)
// {
// 	int	zoom;
// 	int	x;
// 	int	y;

// 	x = 0;
// 	y = 0;
// 	while (1)
// 	{
// 		if (x * bag->mlx->width)
// 	}
// }

void	create_wireframe(t_bag *bag)
{
	int	x;
	int	y;
	//t_coords	p;
	int	zoom = 30;

	bag->og_wf->canva->img = mlx_new_image(bag->mlx->mlx_ptr, bag->mlx->width, bag->mlx->height);
	bag->og_wf->canva->addr = mlx_get_data_addr(bag->og_wf->canva->img, &bag->og_wf->canva->bits_per_pixel, &bag->og_wf->canva->line_length, &bag->og_wf->canva->endian);
	//zoom = get_zoom(bag);
	y = 0;
	while (y < bag->ordinate_len)
	{
		x = 0;
		while (x < bag->axis_len)
		{
			// p = assign_coords(bag, x, y);
			// my_mlx_pixel_put(bag->og_wf->canva, p.x, p.y, p.colour);
			draw_line(bag, assign_coords(bag, x - 1, y, zoom), assign_coords(bag, x , y, zoom));
			draw_line(bag, assign_coords(bag, x, y, zoom), assign_coords(bag, x , y - 1, zoom));
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
	// int	i = 0;
	// while (i < bag->ordinate_len)
	// {
	// 	int	j = 0;
	// 	while (j < bag->axis_len)
	// 	{
	// 		ft_putnbr_fd(bag->map[i][j].altitude, 1);
	// 		write(1, ",", 1);
	// 		ft_putnbr_fd(bag->map[i][j].colour, 1);
	// 		write(1, " ", 1);
	// 		j++;
	// 	}
	// 	write(1, "\n", 1);
	// 	i++;
	// }
	// t_data	img;

	bag->mlx->mlx_ptr = mlx_init();
	if (!bag->mlx->mlx_ptr)
		deallocate(bag);
	bag->mlx->win_ptr = mlx_new_window(bag->mlx->mlx_ptr, bag->mlx->width, bag->mlx->height, "Hello world!");
	if (!bag->mlx->win_ptr)
		deallocate(bag);
	//create_wireframe_image(bag);
	create_wireframe(bag);
	mlx_put_image_to_window(bag->mlx->mlx_ptr, bag->mlx->win_ptr, bag->og_wf->canva->img, 0, 0);
	mlx_hook(bag->mlx->win_ptr, 2, (1L << 0), hooks, bag);
	mlx_hook(bag->mlx->win_ptr, 17, (1L << 2), close_window, bag);
	//mlx_mouse_hook(bag->win->win, mouse_hook, bag);
	mlx_loop(bag->mlx->mlx_ptr);
	return (0);
}
