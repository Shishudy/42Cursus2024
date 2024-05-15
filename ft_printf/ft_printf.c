/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:26:15 by rafasant          #+#    #+#             */
/*   Updated: 2024/05/15 15:21:18 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_format(va_list args, const char *s)
{
	if (*s == '%')
		return (write(1, "%%", 1));
	else if (*s == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (*s == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (*s == 'd')
		return (ft_putstr(ft_itoa_base(va_arg(args, int), "0123456789")));
	else if (*s == 'i')
		return (ft_putstr(ft_itoa_base(va_arg(args, int), "0123456789")));
	else if (*s == 'u')
		return (ft_putstr(ft_itoa_base(va_arg(args, unsigned int) \
		, "0123456789")));
	else if (*s == 'x')
		return (ft_putstr(ft_itoa_base(va_arg(args, unsigned int) \
		, "0123456789abcdef")));
	else if (*s == 'X')
		return (ft_putstr(ft_itoa_base(va_arg(args, unsigned int) \
		, "0123456789ABCDEF")));
	else if (*s == 'p')
		return (ft_putstr("0x") + ft_putstr(ft_itoa_base(va_arg(args, \
		unsigned long), "0123456789abcdef")));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		total;

	if (!s)
		return (-1);
	va_start(args, s);
	// if (!va_arg(args, void *))
	// 	return (-1);
	i = 0;
	total = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			total = total + ft_check_format(args, &s[i]);
		}
		else
			total = total + write(1, &s[i], 1);
		i++;
	}
	va_end(args);
	return (total);
}

int	main(void)
{
	//char	*str = malloc(sizeof(char) * 5);
	printf("%d\n", ft_printf("%p\n", NULL));
	//printf("%d\n", printf("%s\n", NULL));
}