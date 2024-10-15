/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:05:54 by rafasant          #+#    #+#             */
/*   Updated: 2024/10/15 19:30:07 by rafasant         ###   ########.fr       */
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

void	create_wireframe_image(t_bag *bag)
{
	bag->og_wireframe->img = mlx_new_image(bag->mlx->mlx_ptr, bag->mlx->width * 0.8, bag->mlx->height * 0.8);
	bag->og_wireframe->addr = mlx_get_data_addr(bag->og_wireframe->img, &bag->og_wireframe->bits_per_pixel, &bag->og_wireframe->line_length, &bag->og_wireframe->endian);
	int	i = 0;
	int	j = 0;
	while (i < bag->mlx->height * 0.8)
	{
		j = 0;
		while (j < bag->mlx->width * 0.8)
		{
			my_mlx_pixel_put(bag->og_wireframe, j, i, 0xffffff);
			j++;
		}
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
	// while (i < bag->axis_len)
	// {
	// 	int	j = 0;
	// 	while (j < bag->ordinate_len)
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
	mlx_put_image_to_window(bag->mlx->mlx_ptr, bag->mlx->win_ptr, bag->og_wireframe->img, bag->mlx->width * 0.1, bag->mlx->height * 0.1);
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
