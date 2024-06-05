/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:21:37 by rafasant          #+#    #+#             */
/*   Updated: 2024/06/05 16:40:33 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	char	*s;
	int		i;

	s = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!s)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		i;
	int		j;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	if (!s1 && !s2)
		return (ft_strdup(s2));
	s = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!s)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		s[i] = s1[i];
	j = -1;
	while (s2[++j] != '\0')
		s[i + j] = s2[j];
	s[i + j] = '\0';
	return (s);
}

char	*get_buffer(int fd, char *buffer)
{
	char	*buf;
	int		i;
	int		n_read;

	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	n_read = 1;
	while (n_read != 0)
	{
		n_read = read(fd, buf, BUFFER_SIZE);
		if (n_read == -1)
		{
			free(buf);
			free(buffer);
			return (NULL);
		}
		buffer = ft_strjoin(buffer, buf);
		i = 0;
		while (buffer[i] != '\n' && buffer[i] != '\0')
			i++;
		if (buffer[i] == '\n')
			break ;
	}
	free(buf);
	return (buffer);
}

char	*get_str(char *buffer)
{
	int		i;
	char	*str;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		i++;
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		str[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*new_buffer(char *buffer)
{
	int		i;
	int		j;
	char	*new_buffer;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	printf("%d\n", i);
	if (buffer[i] == '\n')
		i++;
	if (i == 0)
		return (free(buffer), NULL);
	new_buffer = malloc(sizeof(char) * ft_strlen(&buffer[i]) + 1);
	if (!new_buffer)
		return (NULL);
	j = 0;
	while (buffer[i + j] != '\0')
	{
		new_buffer[j] = buffer[i + j];
		j++;
	}
	new_buffer[j] = '\0';
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*buffer;

	if (fd == 1)
		return (NULL);
	buffer = get_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	str = get_str(buffer);
	if (!str)
		return (NULL);
	buffer = new_buffer(buffer);
	if (!buffer)
		return (NULL);
	return (str);
}

int	main(int argc, char **argv)
{
	int		fd;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
}