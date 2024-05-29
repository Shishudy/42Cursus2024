/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:21:37 by rafasant          #+#    #+#             */
/*   Updated: 2024/05/29 16:33:12 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_str(int fd, char *buf, char *str)
{
	int		i;
	size_t	n;

	n = read(fd, buf, BUFFER_SIZE);
	i = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	if (buf[i] == '\n')
	{
		str = malloc(sizeof(char) * i + 1);
		if (!str)
			return (NULL);
		i = 0;
		while (buf[i] != '\0')
			str[i] = buf[i];
	}
	return (get_str(fd, buf, str));
}

char	*get_next_line(int fd)
{
	char	*str;
	char	*buf;
	int		i;
	size_t	n;

	n = 1;
	while (n != 0)
	{
		i = 0;
		n = read(fd, buf, BUFFER_SIZE);
		if (n == -1)
			return (ft_free());
		while (buf[i] != '\n' && buf[i] != '\0')
			i++;
		
		
	}
	n = read(fd, buf, BUFFER_SIZE);

	str = get_str(fd, NULL, NULL);
	return (str);
}