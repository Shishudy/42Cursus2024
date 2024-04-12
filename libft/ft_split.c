/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:15:39 by rafasant          #+#    #+#             */
/*   Updated: 2024/04/11 16:03:29 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_str_count(char const *s, char c)
{
	int	i;
	int	n_words;

	i = 0;
	n_words = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			n_words++;
		i++;
	}
	return (n_words);
}

static char	*ft_str(char const *s, int n)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * n + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (*s && i != n)
	{
		str[i] = *s;
		s++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		nstrs;
	char	**strs;

	strs = malloc(sizeof(char *) * ft_str_count(s, c) + 1);
	if (!strs)
		return (NULL);
	nstrs = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		j = 0;
		while (s[i + j] != c && s[i + j] != '\0')
			j++;
		strs[nstrs++] = ft_str(&s[i], j);
		i = i + j;
	}
	strs[nstrs] = 0;
	return (strs);
}

// int	main(void)
// {
// 	char	**strs;
// 	int		i;

// 	strs = ft_split("Hello Here I Am", ' ');
// 	i = 0;
// 	while (strs[i] != 0)
// 	{
// 		printf("%s\n", strs[i]);
// 		i++;
// 	}
// }