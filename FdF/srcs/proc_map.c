/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:18:15 by rafasant          #+#    #+#             */
/*   Updated: 2024/10/14 20:39:30 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

void	get_max_ordinates(t_bag *bag)
{
	char	*line;
	int		check_axis;
	int		i;

	get_fd(bag);
	line = get_next_line(bag->fd);
	while (line != NULL)
	{
		i = 0;
		check_axis = 0;
		while (line[i] != '\0')
		{
			if (line[i] == ' ')
				check_axis++;
			i++;
		}
		free(line);
		if (bag->axis_len == 0)
			bag->axis_len = check_axis;
		else if (bag->axis_len != check_axis)
			deallocate(bag);
		bag->ordinate_len++;
		line = get_next_line(bag->fd);
	}
}

void	allocate_map(t_bag *bag)
{
	int	i;

	get_max_ordinates(bag);
	bag->map = malloc(sizeof(t_map *) * (bag->ordinate_len + 1));
	if (!bag->map)
		deallocate(bag);
	i = 0;
	while (i < bag->ordinate_len)
	{
		bag->map[i] = malloc(sizeof(t_map) * (bag->axis_len + 1));
		if (!bag->map[i])
			deallocate(bag);
		i++;
	}
	bag->map[i] = 0;
}

void	process_line(t_bag *bag, char *line, int i)
{
	char	**num_colour;
	char	**split_num_colour;
	int		k;

	num_colour = ft_split(line, ' ');
	if (!num_colour)
		deallocate(bag);
	k = 0;
	while (k < bag->axis_len)
	{
		split_num_colour = ft_split(num_colour[k], ',');
		if (!split_num_colour)
			deallocate(bag);
		bag->map[i][k].altitude = ft_atoi(split_num_colour[0]);
		bag->map[i][k].colour = 16777215;
		if (split_num_colour[1])
			bag->map[i][k].colour = ft_atoi_base(&split_num_colour[1][2], \
			"0123456789abcdef");
		ft_free(split_num_colour);
		k++;
	}
	ft_free(num_colour);
}
