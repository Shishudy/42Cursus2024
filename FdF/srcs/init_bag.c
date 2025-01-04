/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:07:24 by rafasant          #+#    #+#             */
/*   Updated: 2025/01/04 21:38:05 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

void	get_fd(t_bag *bag)
{
	if (bag->fd)
		close(bag->fd);
	bag->fd = open(bag->file, O_RDONLY);
	if (bag->fd == -1)
		deallocate(bag);
}

void	create_map(t_bag *bag)
{
	int		i;
	char	*line;

	if (ft_strncmp(&bag->file[ft_strlen(bag->file) - 4], ".fdf", 5))
		deallocate(bag);
	allocate_map(bag);
	get_fd(bag);
	i = 0;
	line = NULL;
	while (i < bag->ordinate_len)
	{
		line = get_next_line(bag->fd);
		if (!line)
			deallocate(bag);
		process_line(bag, line, i);
		free(line);
		i++;
	}
	close(bag->fd);
}

void	init_og_wf(t_bag *bag)
{
	bag->og_wf = malloc(sizeof(t_wf));
	if (!bag->og_wf)
		deallocate(bag);
	bag->og_wf->canva = malloc(sizeof(t_data));
	if (!bag->og_wf->canva)
		deallocate(bag);
	bag->og_wf->canva->img = mlx_new_image(bag->mlx->mlx_ptr, bag->mlx->width, bag->mlx->height);
	if (!bag->og_wf->canva->img)
		deallocate(bag);
	bag->og_wf->canva->addr = mlx_get_data_addr(bag->og_wf->canva->img, &bag->og_wf->canva->bits_per_pixel, &bag->og_wf->canva->line_length, &bag->og_wf->canva->endian);
	if (!bag->og_wf->canva->addr)
		deallocate(bag);
	bag->og_wf->x = bag->mlx->width / 2;
	bag->og_wf->y = bag->mlx->height / 2;
	bag->og_wf->x_angle = 0;
	bag->og_wf->y_angle = 0;
	bag->og_wf->z_angle = 0;
	bag->og_wf->pers = 0;
	bag->og_wf->zoom = 30;
	bag->mod_wf = NULL;
}

t_bag	*create_bag(char *file)
{
	t_bag	*bag;

	bag = malloc(sizeof(t_bag));
	if (!bag)
		exit (1);
	bag->axis_len = 0;
	bag->ordinate_len = 0;
	bag->fd = 0;
	bag->file = file;
	bag->mlx = malloc(sizeof(t_mlx));
	if (!bag->mlx)
		deallocate(bag);
	bag->mlx->width = 1920;
	bag->mlx->height = 1080;
	bag->max_z = 0;
	bag->mlx->mlx_ptr = mlx_init();
	if (!bag->mlx->mlx_ptr)
		deallocate(bag);
	bag->mlx->win_ptr = mlx_new_window(bag->mlx->mlx_ptr, bag->mlx->width, bag->mlx->height, "FdF");
	if (!bag->mlx->win_ptr)
		deallocate(bag);
	init_og_wf(bag);
	create_map(bag);
	return (bag);
}
