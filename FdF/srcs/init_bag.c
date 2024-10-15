/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:07:24 by rafasant          #+#    #+#             */
/*   Updated: 2024/10/15 19:24:23 by rafasant         ###   ########.fr       */
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

t_bag	*create_bag(char *file)
{
	t_bag	*bag;

	bag = malloc(sizeof(t_bag));
	if (!bag)
		exit (1);
	bag->mlx = malloc(sizeof(t_mlx));
	if (!bag->mlx)
		deallocate(bag);
	bag->og_wireframe = malloc(sizeof(t_data));
	if (!bag->og_wireframe)
		deallocate(bag);
	bag->mlx->width = 1920;
	bag->mlx->height = 1080;
	bag->axis_len = 0;
	bag->ordinate_len = 0;
	bag->fd = 0;
	bag->file = file;
	create_map(bag);
	return (bag);
}
