/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:21:37 by rafasant          #+#    #+#             */
/*   Updated: 2024/06/16 23:38:24 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*str;
	static char	buffer[BUFFER_SIZE];

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (buffer[0] == '\0')
	{
		if (read(fd, buffer, BUFFER_SIZE) <= 0)
			return (NULL);
	}
	str = get_str(fd, buffer, NULL);
	if (!str)
		return (NULL);
	return (str);
}
