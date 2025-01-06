/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:07:24 by rafasant          #+#    #+#             */
/*   Updated: 2025/01/06 22:03:57 by rafasant         ###   ########.fr       */
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

int	check_line(char *line)
{
	int	i;

	i = 0;
	while (1)
	{
		while (line[i] == ' ')
			i++;
		while (line[i] != ' ' && line[i] != '\0' && line[i] != '\n' && line[i] != ',')
		{
			if (line[i] == '-' && ft_isdigit(line[i + 1]))
				;
			else if (!ft_isdigit(line[i]))
				return (1);
			i++;
		}
		if (line[i] == ',')
		{
			i++;
			while (line[i] != ' ' && line[i] != '\0' && line[i] != '\n')
			{
				if (!ft_isalnum(line[i]))
					return (1);
				i++;
			}
		}
		if (line[i] == '\n' || line[i] == '\0')
		{
			break ;
		}
	}
	return (0);
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
		if (check_line(line))
		{
			free(line);
			deallocate(bag);
		}
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
}

void	init_mlx(t_bag *bag)
{
	bag->mlx = malloc(sizeof(t_mlx));
	if (!bag->mlx)
		deallocate(bag);
	bag->mlx->width = WINDOW_WIDTH;
	bag->mlx->height = WINDOW_HEIGHT;
	bag->mlx->mlx_ptr = mlx_init();
	if (!bag->mlx->mlx_ptr)
		deallocate(bag);
	bag->mlx->win_ptr = mlx_new_window(bag->mlx->mlx_ptr, bag->mlx->width, bag->mlx->height, "FdF");
	if (!bag->mlx->win_ptr)
		deallocate(bag);
}

t_bag	*create_bag(char *file)
{
	t_bag	*bag;

	bag = malloc(sizeof(t_bag));
	if (!bag)
		exit (1);
	bag->axis_len = 0;
	bag->ordinate_len = 0;
	bag->max_z = 0;
	bag->fd = 0;
	bag->file = file;
	bag->mlx = NULL;
	bag->og_wf = NULL;
	bag->mod_wf = NULL;
	bag->map = NULL;
	create_map(bag);
	if (bag->max_z == 0)
		bag->max_z = 1;
	bag->max_z = abs(bag->max_z);
	init_mlx(bag);
	init_og_wf(bag);
	return (bag);
}
