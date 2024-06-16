/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 23:37:38 by rafasant          #+#    #+#             */
/*   Updated: 2024/06/16 23:44:52 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//----------------MANDATORY----------------------

// int	main(int argc, char **argv)
// {
// 	(void)argc;
// 	printf("Text file: %s\n", argv[1]);
// 	// All strings in file
// 	int		fd;
// 	char	*str;

// 	fd = open(argv, O_RDONLY);
// 	str = get_next_line(fd);
// 	while (str)
// 	{
// 		printf("%s\n", str);
// 		free(str);
// 		str = get_next_line(fd);
// 	}
// 	close(fd);

// 	// Only N strings in file
// 	int	n = 0;

// 	fd = open(argv, O_RDONLY);
// 	str = get_next_line(fd);
// 	while (n < 5)
// 	{
// 		printf("%s\n", str);
// 		free(str);
// 		str = get_next_line(fd);
// 		n++;
// 	}
// 	if (str)
// 		free(str);
// 	close(fd);
// }

//-------------------BONUS-----------------------

static int	ft_nlen(long int n)
{
	int	nlen;

	if (n == 0)
		return (1);
	nlen = 0;
	if (n < 0)
		nlen++;
	while (n != 0)
	{
		n = n / 10;
		nlen++;
	}
	return (nlen);
}

char	*ft_itoa(int n)
{
	long int	ln;
	int			nlen;
	char		*nstr;

	ln = n;
	nlen = ft_nlen(ln);
	nstr = malloc(sizeof(char) * nlen + 1);
	if (!nstr)
		return (NULL);
	nstr[nlen--] = '\0';
	if (ln < 0)
	{
		ln = -ln;
		nstr[0] = '-';
	}
	while (ln > 9)
	{
		nstr[nlen--] = ln % 10 + '0';
		ln = ln / 10;
	}
	nstr[nlen] = ln % 10 + '0';
	return (nstr);
}

void	create_fds(void)
{
	FILE	*fptr;
	char	*path;
	char	*str;
	int		fd;
	int		i;

	i = 0;
	while (i < 10)
	{
		path = ft_itoa(i);
		printf("filename: %s\n", path);
		fptr = fopen(path, "w+");
		if (fptr == NULL)
			printf("Unable to create file.\n");
		fputs(path, fptr);
		fclose(fptr);
		fd = open(path, O_RDONLY);
		if (fd == -1)
			break ;
		printf("open: %d\n", fd);
		str = get_next_line(fd);
		if (!str)
			printf("failed str?: %s\n", str);
		while (str)
		{
			printf("str: %s\n", str);
			free(str);
			str = get_next_line(fd);
		}
		printf("unlink: %d\n", unlink(path));
		//printf("close: %d\n", close(fd));
		printf("\n");
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*str;
	int		i;

	(void)argc;
	if (argv[1])
	{
		i = 1;
		printf("Test file:\n");
		while (argv[i])
		{
			printf("Test file: %s\n", argv[i]);
			fd = open(argv[i], O_RDONLY);
			str = get_next_line(fd);
			while (str)
			{
				printf("%s\n", str);
				free(str);
				str = get_next_line(fd);
			}
			i++;
		}
	}
	else
		create_fds();
}
