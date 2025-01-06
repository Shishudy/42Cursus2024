/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:18:15 by rafasant          #+#    #+#             */
/*   Updated: 2025/01/06 17:51:03 by rafasant         ###   ########.fr       */
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
		while (line[i] != '\0' && line[i] != '\n')
		{
			if (line[i] != ' ' && (line[i + 1] == ' ' || \
			line[i + 1] == '\n' || line[i + 1] == '\0'))
				check_axis++;
			i++;
		}
		free(line);
		if (bag->axis_len == 0)
			bag->axis_len = check_axis;
		if (check_axis != bag->axis_len)
			deallocate(bag);
		bag->ordinate_len++;
		line = get_next_line(bag->fd);
	}
}

void	allocate_map(t_bag *bag)
{
	int	i;

	get_max_ordinates(bag);
	if (bag->axis_len == 0 || bag->ordinate_len == 0)
		deallocate(bag);
	bag->map = malloc(sizeof(t_map *) * (bag->ordinate_len + 1));
	if (!bag->map)
		deallocate(bag);
	i = 0;
	while (i < bag->ordinate_len)
	{
		bag->map[i] = malloc(sizeof(t_map) * (bag->axis_len));
		if (!bag->map[i])
			deallocate(bag);
		i++;
	}
	bag->map[i] = 0;
}

void	assign_altitude(t_bag *bag, t_map *map, char *altitude)
{
	map->altitude = ft_atoi(altitude);
	if (map->altitude > bag->max_z)
		bag->max_z = map->altitude;
}

char	*pick_base(char *colour)
{
	int	i;

	i = 0;
	while (colour[i])
	{
		if (ft_isalpha(colour[i]))
		{
			if (colour[i] >= 'A' && colour[i] <= 'Z')
				return ("0123456789ABCDEF");
		}
		i++;
	}
	return ("0123456789abcdef");
}

void	assign_colour(t_map *map, char *colour)
{
	if (colour)
		map->colour = ft_atoi_base(colour, pick_base(colour));
	if (map->colour == -1)
		map->colour = DEFAULT_COLOUR;
}

void	process_line(t_bag *bag, char *line, int i)
{
	int		k;
	char	**num_colour_n;
	char	**num_colour;
	char	**split_num_colour;

	num_colour_n = ft_split(line, '\n');
	if (!num_colour_n)
		deallocate(bag);
	num_colour = ft_split(num_colour_n[0], ' ');
	ft_free(num_colour_n);
	if (!num_colour)
		deallocate(bag);
	k = 0;
	while (k < bag->axis_len)
	{
		split_num_colour = ft_split(num_colour[k], ',');
		if (!split_num_colour)
		{
			ft_free(split_num_colour);
			ft_free(num_colour);
			deallocate(bag);
		}
		assign_altitude(bag, &bag->map[i][k], split_num_colour[0]);
		bag->map[i][k].colour = DEFAULT_COLOUR;
		if (split_num_colour[1])
			assign_colour(&bag->map[i][k], &split_num_colour[1][2]);
		ft_free(split_num_colour);
		k++;
	}
	ft_free(num_colour);
}
