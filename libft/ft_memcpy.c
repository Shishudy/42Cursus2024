/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:48:21 by rafasant          #+#    #+#             */
/*   Updated: 2024/02/20 12:54:45 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char	*dest;
	char	*source;


	dest = dst;
	source = src;
	while (*source != '\0')
	{
		*dest = *source;
		dest++;
		source++;
	}
	return (dst);
}

#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*src;

	src = ft_strdup("hello");
	printf("%p\n", ft_memmove(src, &src[2], 6));
	printf("%s\n", src);
	src = ft_strdup("goodbye");
	printf("%p\n", memmove(&src[2], src, 8));
	printf("%s\n", src);
}