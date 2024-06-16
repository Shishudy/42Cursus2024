/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:07:40 by rafasant          #+#    #+#             */
/*   Updated: 2024/06/16 17:51:37 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*str;
	static char	buffer[FOPEN_MAX][BUFFER_SIZE];

	if (fd < 0 || BUFFER_SIZE < 1 || fd > FOPEN_MAX)
		return (NULL);
	if (buffer[fd][0] == '\0')
	{
		if (read(fd, buffer[fd], BUFFER_SIZE) <= 0)
			return (NULL);
	}
	str = get_str(fd, buffer[fd], NULL);
	if (!str)
		return (NULL);
	return (str);
}

// int	main(int argc, char **argv)
// {
// 	int		fd;
// 	char	*str;

// 	(void)argc;
// 	fd = open(argv[1], O_RDONLY);
// 	str = get_next_line(fd);
// 	// while (str)
// 	// {
// 	// 	printf("%s\n", str);
// 	// 	free(str);
// 	// 	str = get_next_line(fd);
// 	// }
// 	int	i = 0;
// 	while (i < 5)
// 	{
// 		printf("%s\n", str);
// 		free(str);
// 		str = get_next_line(fd);
// 		i++;
// 	}
// 	free(str);
// 	close(fd);
// }