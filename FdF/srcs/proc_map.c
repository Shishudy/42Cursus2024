/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:18:15 by rafasant          #+#    #+#             */
/*   Updated: 2024/10/09 19:49:11 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

void	read_map(t_bag *bag, char *file)
{
	
}

int	n_lines(int	fd)
{
	int		n_lines;
	char	*line;

	n_lines = 0;
	line = NULL;
	while (1)
	{
		if (line)
			free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		n_lines++;
	}
	return (n_lines);
}

void	split_atoi(t_bag *bag, char **argv)
{
	int	sign;
	int	x;

	while ((**argv == 32 || (**argv >= 9 && **argv <= 13)) && **argv)
		(*argv)++;
	if (**argv == '-' && (**argv + 1 < '0' || **argv + 1 > '9'))
	{
		sign = -1;
		(*argv)++;
	}
	if (((**argv < '0' || **argv > '9') && **argv != '\0') || \
	(sign == -1 && **argv == '\0'))
		deallocate(bag);
	while (**argv >= '0' && **argv <= '9' && **argv != '\0')
	{
		if (x * 10 < x)
			deallocate(bag);
		x = x * 10 + **argv - '0';
		(*argv)++;
	}
	if (x * sign > 2147483647 || x * sign < \
	-2147483648 || (**argv != 32 && (**argv <= 9 || **argv >= 13) && **argv))
		deallocate(bag);
	x = x * sign;
}

void	check_line(t_bag *bag, char *line)
{
	int	n_spaces;

	n_spaces = 0;
	while (line != '\0')
	{
		if (*line == ' ')
			n_spaces++;
		line++;
	}
	if (bag->map->axis == 0)
		bag->map->axis = n_spaces;
	else if (n_spaces != bag->map->axis)
		deallocate(bag);
}

void	allocate_map(t_bag *bag, char *file, int fd)
{
	char	*line;
	int		lines;

	lines = n_lines(fd);
	bag->map->map = malloc(sizeof(int *) * lines + 1);
	if (!bag->map->map)
		deallocate(bag);
	while (bag->map->ordinate < lines)
	{
		line = get_next_line(fd);
		if (!line)
			deallocate(bag);
		check_line(bag, line);
		line_len = ft_strlen(line);
		if (line_len != )
		// bag->map->map[i] = malloc(sizeof(char) * ft_strlen(line) + 1);
		// if (!bag->map->map[i])
		// 	deallocate(bag);
		bag->map->map[bag->map->ordinate] = line;
		bag->map->ordinate++;
	}
	bag->map->map[bag->map->ordinate] = 0;
}

int	check_map(t_bag *bag, char *file)
{
	int		fd;

	if (ft_strncmp(&file[ft_strlen(file) - 3], ".fdf", 5))
		deallocate(bag);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		deallocate(bag);
	return (fd);
}

void	create_map(t_bag *bag, char *file)
{
	int	fd;

	fd = check_map(bag, file);
	read_map(bag, file);
}

t_bag	*create_bag(char *file)
{
	t_bag	*bag;

	bag = malloc(sizeof(t_bag));
	if (!bag)
		exit (1);
	bag->map = malloc(sizeof(t_map));
	if (!bag->map)
		deallocate(bag);
	create_map(&bag->map, file);

}