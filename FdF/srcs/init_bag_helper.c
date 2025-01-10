/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bag_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:27:07 by rafasant          #+#    #+#             */
/*   Updated: 2025/01/08 17:34:01 by rafasant         ###   ########.fr       */
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
	while (1)
	{
		while (*line == ' ')
			line++;
		while (*line != ' ' && *line != '\0' && *line != '\n' && *line != ',')
		{
			if (*line == '-' && ft_isdigit(*(line + 1)))
				;
			else if (!ft_isdigit(*line))
				return (1);
			line++;
		}
		if (*line == ',')
		{
			if (!(*(line + 1) && *(line + 2) && *(line + 1) == '0' && \
			*(line + 2) == 'x'))
				return (1);
			while (*++line != ' ' && *line != '\0' && *line != '\n')
				if (!ft_isalnum(*line))
					return (1);
		}
		if (*line == '\n' || *line == '\0')
			break ;
	}
	return (0);
}
