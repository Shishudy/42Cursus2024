/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:05:54 by rafasant          #+#    #+#             */
/*   Updated: 2024/11/30 22:42:04 by rafasant         ###   ########.fr       */
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

void	rotate_iso(t_coords *point)
{
	int	prev_x;
	int	prev_y;

	prev_x = point->x;
	prev_y = point->y;
	point->x = (int)(sin(45) * (point->x - point->y));
	point->y = -(int)(cos(35.264) * (sin(45) * (prev_x + prev_y)) - sin(35.264) * point->z);
}

t_coords	assign_coords(t_bag *bag, int x, int y, int zoom)
{
	t_coords	coords;

	if (x == -1)
		x = 0;
	if (y == -1)
		y = 0;
	coords.x = x * zoom + (bag->og_wf->x - (bag->axis_len * zoom / 2)); //zoom
	coords.y = y * zoom + (bag->og_wf->y - (bag->ordinate_len * zoom / 2));
	coords.z = bag->map[y][x].altitude * zoom;
	coords.colour = bag->map[y][x].colour;
	return (coords);
}

// int	colour_diff(t_coords prev, t_coords curr, float step)
// {
// 	int	colour;

// 	colour = curr.colour - prev.colour;
// 	colour = colour / step;
// 	return (colour);
// }

void	draw_line(t_bag *bag, t_coords prev, t_coords curr)
{
	float	diff_y;
	float	diff_x;
	float	step;

	rotate_iso(&prev);
	rotate_iso(&curr);
	diff_y = curr.y - prev.y;
	diff_x = curr.x - prev.x;
	if (fabs(diff_y) > fabs(diff_x))
		step = fabs(diff_y);
	else
		step = fabs(diff_x);
	diff_y = diff_y / step;
	diff_x = diff_x / step;
	while (!(prev.x == curr.x && prev.y == curr.y))
	{
		if (prev.x >= 0 && prev.y >= 0 && prev.x <= bag->mlx->width && prev.y <= bag->mlx->height)
			my_mlx_pixel_put(bag->og_wf->canva, prev.x, prev.y, prev.colour);
		prev.x = prev.x + diff_x;
		prev.y = prev.y + diff_y;
		ft_printf("%d, %d\n", prev.x, prev.y);
		ft_printf("%d, %d\n", curr.x, curr.y);
	}
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
