/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:05:54 by rafasant          #+#    #+#             */
/*   Updated: 2024/11/08 19:15:37 by rafasant         ###   ########.fr       */
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

int	rotate_y(int x, int y, int z, float angle)
{
	(void)angle;
	return (-(int)(cos(35.264) * (sin(45) * (x + y)) - sin(35.264) * z));
	//return ((int)(x * sin(angle) + y * cos(angle)));
}

int	rotate_x(int x, int y, float angle)
{
	//(void)angle;
	return ((int)(sin(angle) * (x - y)));
	//return ((int)(x * cos(angle) - y * sin(angle)));
}

// void	create_lines(t_bag *bag, int diff_x, int diff_y)
// {
// 	int	x;
// 	int	y;

// 	(void)bag;
// 	if (diff_y < 0)
// 		diff_y = -diff_y;
// 	x = 0;
// 	while (y < diff_y)
// 	{
		
// 	}
// }

void	draw_line(t_bag *bag, float prev_x, float prev_y, int x, int y)
{
	float	diff_y;
	float	diff_x;
	float	step;

	diff_y = y - prev_y;
	diff_x = x - prev_x;
	if (fabs(diff_y) > fabs(diff_x))
		step = fabs(diff_y);
	else
		step = fabs(diff_x);
	diff_y = diff_y / step;
	diff_x = diff_x / step;
	while (prev_x != x && prev_y != y)
	{
		my_mlx_pixel_put(bag->og_wf->canva, prev_x, prev_y, 0xffffff);
		prev_x = prev_x + diff_x;
		prev_y = prev_y + diff_y;
	}
}

void	create_wireframe_image(t_bag *bag)
{
	int x = 0;
	int y = 0;
	int prev_x;
	int prev_y;
	int	i;
	int j;
	
	bag->og_wf->canva->img = mlx_new_image(bag->mlx->mlx_ptr, bag->mlx->width, bag->mlx->height);
	bag->og_wf->canva->addr = mlx_get_data_addr(bag->og_wf->canva->img, &bag->og_wf->canva->bits_per_pixel, &bag->og_wf->canva->line_length, &bag->og_wf->canva->endian);
	i = 0;
	while (i < bag->ordinate_len)
	{
		j = 0;
		while (j < bag->axis_len)
		{
			prev_x = x;
			prev_y = y;
			x = rotate_x((j * bag->mlx->width * 0.3) / bag->axis_len, (i * bag->mlx->height * 0.3) / bag->ordinate_len, 45) + 860;
			y = rotate_y((j * bag->mlx->width * 0.3) / bag->axis_len, (i * bag->mlx->height * 0.3) / bag->ordinate_len, (int)((bag->map[i][j]).altitude * bag->mlx->height * 0.10) / bag->ordinate_len, 45) + 300;
			if ((x >= 0 && y >= 0) && (x <= bag->mlx->width && y <= bag->mlx->height) && prev_x != 0 && prev_y != 0)
			{
				draw_line(bag, prev_x, prev_y, x, y);
				if (i - 1 > 0)
				{
					prev_x = x;
					prev_y = y;
					x = rotate_x((j * bag->mlx->width * 0.3) / bag->axis_len, ((i - 1) * bag->mlx->height * 0.3) / bag->ordinate_len, 45) + 860;
					y = rotate_y((j * bag->mlx->width * 0.3) / bag->axis_len, ((i - 1) * bag->mlx->height * 0.3) / bag->ordinate_len, (int)((bag->map[i - 1][j]).altitude * bag->mlx->height * 0.10) / bag->ordinate_len, 45) + 300;
				}
				draw_line(bag, prev_x, prev_y, x, y);
			}
			j++;
		}
		prev_x = 0;
		prev_y = 0;
		i++;
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
	create_wireframe_image(bag);
	mlx_put_image_to_window(bag->mlx->mlx_ptr, bag->mlx->win_ptr, bag->og_wf->canva->img, 0, 0);
	// img.img = mlx_new_image(bag->win->mlx, 1920, 1080);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// my_mlx_pixel_put(&img, 5, 5, 0xffffff );
	// my_mlx_pixel_put(&img, 5, 6, 0 );
	// my_mlx_pixel_put(&img, 5, 7, 0xffffff );
	// mlx_put_image_to_window(bag->win->mlx, bag->win->win, img.img, 0, 0);
	// mlx_destroy_image(bag->win->mlx, img.img);
	// mlx_clear_window(bag->win->mlx, bag->win->win);
	mlx_hook(bag->mlx->win_ptr, 2, (1L << 0), hooks, bag);
	mlx_hook(bag->mlx->win_ptr, 17, (1L << 2), close_window, bag);
	//mlx_mouse_hook(bag->win->win, mouse_hook, bag);
	mlx_loop(bag->mlx->mlx_ptr);
	return (0);
}
