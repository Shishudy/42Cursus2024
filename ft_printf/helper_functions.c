/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:43:48 by rafasant          #+#    #+#             */
/*   Updated: 2024/05/18 12:43:05 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(const char *s)
{
	int	i;

	if (!s)
		return (ft_putstr("(null)"));
	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_new_str_len(long int n, int base_len)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i = 1;
	}
	while (n >= base_len)
	{
		n = n / base_len;
		i++;
	}
	i++;
	return (i);
}

int	ft_itoa_base(long int n, char *base_to)
{
	int		base_len;
	int		str_len;
	char	*str;

	base_len = ft_strlen(base_to);
	str_len = ft_new_str_len(n, base_len);
	str = malloc(sizeof(char) * str_len + 1);
	if (!str)
		return (-1);
	str[str_len--] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n >= base_len)
	{
		str[str_len] = base_to[n % base_len];
		n = n / base_len;
		str_len--;
	}
	str[str_len] = base_to[n % base_len];
	str_len = ft_putstr(str);
	free(str);
	return (str_len);
}
