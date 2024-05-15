/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:26:15 by rafasant          #+#    #+#             */
/*   Updated: 2024/05/06 12:53:47 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	printf("%d\n", str_len);
	str = malloc(sizeof(char) * str_len + 1);
	if (!str)
		return (NULL);
	str[str_len] = '\0';
	while (n2 > 0)
	{
		str[--str_len] = base_to[n2 % base_len];
		printf("%c\n", str );

		n2 = n2 / base_len;
	}
	if (n < 0)
		str[str_len] = '-';
	return (str);
}

// int	ft_putstr(char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		write(1, &s[i], 1);
// 		i++;
// 	}
// 	return (i);
// }

// int	ft_check_format(va_list va_args, const char *s)
// {
// 	(void)va_args;
// 	if (*s == '%')
// 		return (write(1, "%%", 1));
// 	else if (*s == 'c')
// 		return (write(1, &va_args, 1));
// 	else if (*s == 's')
// 		return (ft_putstr(va_args));
// 	else if (*s == 'd')
// 		return (ft_itoa_base(va_args, "0123456789"));
// 	else if (*s == 'i')
// 		return (ft_itoa_base(va_args, "0123456789"));
// 	else if (*s == 'u')
// 		return (ft_itoa_base((unsigned int)va_args, "0123456789"));
// 	else if (*s == 'x')
// 		return (ft_itoa_base(va_args, "0123456789abcdef"));
// 	else if (*s == 'X')
// 		return (ft_itoa_base(va_args, "0123456789ABCDEF"));
// 	else if (*s == 'p')
// 		return (ft_putstr("0x") + ft_itoa_base(va_args, "0123456789abcdef"));
// 	return (0);
// }

// int	ft_printf(const char *s, ...)
// {
// 	va_list	va_args;
// 	int		i;
// 	int		total;

// 	if (!s)
// 		return (0);
// 	va_start(va_args, s);
// 	i = 0;
// 	total = 0;
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] == '%')
// 		{
// 			i++;
// 			total = total + ft_check_format(va_args, &s[i]);
// 		}
// 		else
// 		{
// 			total = total + write(1, &s[i], 1);
// 		}
// 		i++;
// 	}
// 	va_end(va_args);
// 	return (total);
// }

int	main(void)
{
	printf("%s\n", ft_itoa_base(-204492, "0123456789abcdef"));
	//printf("%d\n", ft_printf("%%\n", "str"));
}