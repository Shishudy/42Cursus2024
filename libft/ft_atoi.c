/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:38:29 by rafasant          #+#    #+#             */
/*   Updated: 2024/04/19 23:54:07 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	n;
	int	i;
	int	flag;

	// if (!nptr)
	// 	return (0);
	n = 0;
	i = 0;
	flag = 1;
	while (nptr[i] != '\0' && ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' '))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			flag = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
		n = n * 10 + nptr[i++] - '0';
	return (n * flag);
}

// int	main(void)
// {
// 	printf("%d\n", ft_atoi("-2147483648"));
// }