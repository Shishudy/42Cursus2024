/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:26:15 by rafasant          #+#    #+#             */
/*   Updated: 2024/05/17 15:34:04 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_format(va_list args, const char *s)
{
	unsigned long	i;

	if (*s == '%')
		return (write(1, "%%", 1));
	else if (*s == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (*s == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (*s == 'd' || *s == 'i')
		return (ft_itoa_base(va_arg(args, int), "0123456789"));
	else if (*s == 'u')
		return (ft_itoa_base(va_arg(args, unsigned int), "0123456789"));
	else if (*s == 'x')
		return (ft_itoa_base(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (*s == 'X')
		return (ft_itoa_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (*s == 'p')
	{
		i = va_arg(args, unsigned long int);
		if (i == 0)
			return (write(1, "(nil)", 5));
		return (ft_putstr("0x") + ft_putptr(i, "0123456789abcdef"));
	}
	return (write(1, "%%", 1) + write(1, &*s, 1));
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		total;
	int		value;

	if (!s)
		return (-1);
	va_start(args, s);
	total = 0;
	while (*s != '\0')
	{
		if (*s == '%')
		{
			s++;
			value = ft_check_format(args, &*s);
			if (value == -1)
				return (-1);
			total = total + value;
		}
		else
			total = total + write(1, &*s, 1);
		s++;
	}
	va_end(args);
	return (total);
}

int	main(void)
{
	// char	*str = malloc(sizeof(char) * 5);

	// printf("%d\n", ft_printf("%i\n", -2147483648));
	// printf("%d\n", ft_printf("%i\n", 0));
	// printf("%d\n", ft_printf("%i\n", 2147483647));
	// printf("%d\n", ft_printf("%p\n", NULL));
	// printf("%d\n", printf("%p\n", NULL));
	// printf("%d\n", ft_printf("%p\n", str));
	// printf("%d\n", printf("%p\n", str));
	// printf("%d\n", ft_printf("%s\n", NULL));
	// free(str);
	//printf("%d\n", printf("%s\n", NULL));
	//printf("%d\n", ft_printf(" %d ", 10));
	// printf("%d\n", printf(" %r ", -1));
	// printf("%d\n", ft_printf(" %a%o ", -1));
	// printf("%d\n", ft_printf(" %d ", -1));
	printf("LEN:%d\n", ft_printf("1st: %p 2nd: %p \n", 9223372036854775807, LONG_MAX));
	printf("LEN:%d\n", ft_printf("1st: %p 2nd: %p \n", 18446744073709551615, -18446744073709551615));
}
