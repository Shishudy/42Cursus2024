/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:31:16 by rafasant          #+#    #+#             */
/*   Updated: 2024/04/19 00:15:47 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 == *s2 && n > 0 && *s1 != '\0')
	{
		s1++;
		s2++;
		n--;
	}
	return ((int)(*s1 - *s2));
}

// int	main(void)
// {
// 	char	*s1;
// 	char	*s2;

// 	s1 = "hello there";
// 	s2 = "hello*there";
// 	if (ft_strncmp(s1, s2, 11) > 0)
// 		return (printf("%s\n", "s1 maior que s2"));
// 	if (ft_strncmp(s1, s2, 11) == 0)
// 		return (printf("%s\n", "s1 igual a s2"));
// 	if (ft_strncmp(s1, s2, 11) < 0)
// 		return (printf("%s\n", "s1 menor que s2"));
// }