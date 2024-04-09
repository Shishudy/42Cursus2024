/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:51:34 by rafasant          #+#    #+#             */
/*   Updated: 2024/03/13 14:18:33 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*source;

	if (!dst)
		return (NULL);
	dest = dst;
	source = src;
	if (dst <= src)
	{
		while (len-- != 0)
			*dest++ = *source++;
	}
	else
	{
		dest = dest + len;
		source = source + len;
		while (len-- != 0)
			*--dest = *--source;
	}
	return (dst);
}

#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*src;
	char	*dst;

	src = ft_strdup("hello");
	printf("%p\n", ft_memmove(&src[1], &src[2], 2));
	printf("%s\n", src);
	dst = ft_strdup("hello");
	printf("%p\n", memmove(&dst[1], &dst[2], 2));
	printf("%s\n", dst);
}