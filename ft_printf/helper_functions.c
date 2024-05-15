/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:43:48 by rafasant          #+#    #+#             */
/*   Updated: 2024/05/15 14:58:02 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_new_str_len(long n, char *base_to)
{
	int	i;
	int	base_len;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i = 1;
	}
	base_len = ft_strlen(base_to);
	while (n > 0)
	{
		n = n / base_len;
		i++;
	}
	return (i);
}

char	*ft_itoa_base(int n, char *base_to)
{
	int		base_len;
	int		str_len;
	long	n2;
	char	*str;

	n2 = n;
	if (n2 < 0)
		n2 = -n2;
	base_len = ft_strlen(base_to);
	str_len = ft_new_str_len(n, base_to);
	str = malloc(sizeof(char) * str_len + 1);
	if (!str)
		return (NULL);
	str[str_len--] = '\0';
	while (n2 > 0)
	{
		str[str_len] = base_to[n2 % base_len];
		n2 = n2 / base_len;
		str_len--;
	}
	if (n < 0)
		str[str_len] = '-';
	return (str);
}
