/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:18:15 by rafasant          #+#    #+#             */
/*   Updated: 2025/01/08 16:37:14 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

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

void	assign_colour(t_map *map, char **split_num_colour)
{
	map->colour = DEFAULT_COLOUR;
	if (split_num_colour[1])
		map->colour = ft_atoi_base(&split_num_colour[1][2], \
		pick_base(&split_num_colour[1][2]));
	if (map->colour == -1)
		map->colour = DEFAULT_COLOUR;
}

int	process_line(t_bag *bag, char *line, int i)
{
	int		k;
	char	**num_colour_n;
	char	**num_colour;
	char	**split_num_colour;

	num_colour_n = ft_split(line, '\n');
	if (!num_colour_n)
		return (0);
	num_colour = ft_split(num_colour_n[0], ' ');
	ft_free(num_colour_n);
	if (!num_colour)
		return (0);
	k = 0;
	while (k < bag->axis_len)
	{
		split_num_colour = ft_split(num_colour[k], ',');
		if (!split_num_colour)
			return (ft_free(num_colour), 0);
		assign_altitude(bag, &bag->map[i][k], split_num_colour[0]);
		assign_colour(&bag->map[i][k], split_num_colour);
		ft_free(split_num_colour);
		k++;
	}
	return (ft_free(num_colour), 1);
}
