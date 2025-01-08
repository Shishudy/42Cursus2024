/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_map_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:08:16 by rafasant          #+#    #+#             */
/*   Updated: 2025/01/08 16:37:23 by rafasant         ###   ########.fr       */
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
