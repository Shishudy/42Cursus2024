/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:14:47 by rafasant          #+#    #+#             */
/*   Updated: 2024/04/28 14:14:47 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	ft_check_flags(const char *s)
// {

// }

int	ft_width(const char *s, int i, t_printf *format)
{
	int	value;
	int	zeros;

	if (s[i - 1] == '.')
	{
		format->width_max = ft_atoi(&s[i]);
		value = format->width_max;
	}
	else
	{
		format->width_min = ft_atoi(&s[i]);
		value = format->width_min;
	}
	zeros = 0;
	if (s[i] == '0' && s[i - 1] == '.')
	{
		while (s[i + zeros] == '0')
			zeros++;
		return (ft_strlen(ft_itoa(value)) + zeros);
	}
	return (ft_strlen(ft_itoa(value)));
}

void	ft_fill_flags(const char *s, int i, t_printf *format)
{
	if (s[i] == '-')
	{
		if (format->zero_pads == 1)
			format->zero_pads = 0;
		format->left_justify = 1;
	}
	else if (s[i] == '0')
	{
		if (format->left_justify == 1)
			return ;
		format->zero_pads = 1;
	}
	else if (s[i] == '+')
		format->sign = 1;
	else if (s[i] == ' ')
		format->blank = 1;
	else if (s[i] == '#')
		format->hashtag = 1;
	else if (s[i] == '.')
	{
		if (format->zero_pads == 1)
			format->zero_pads = 0;
		format->period = 1;
	}
}

int	ft_flags(const char *s, t_printf *format)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '0' && !(s[i - 1] >= '0' && s[i - 1] <= '9') && s[i - 1] != '.')
			ft_fill_flags(s, i, format);
		else if (s[i] >= '0' && s[i] <= '9')
			i = i + ft_width(s, i, format) - 1;
		else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] >= 'Z'))
			return (i);
		else
			ft_fill_flags(s, i, format);
		i++;
	}
	return (i);
}

void	ft_conversions(const char *s, t_printf *format)
{
	int	i;

	i = 0;
	if (s[i] == '%')
		ft_putchar('%', format);
	else if (s[i] == 'c')
		ft_putchar(va_arg(format->args, int), format);
	else if (s[i] == 's')
	{
		ft_handle_precision(format);
		ft_putstr(va_arg(format->args, char *), format);
	}
	else if (s[i] == 'd')
		ft_putnbr(va_arg(format->args, int), format);
	// else if (s[i] == 'i')
	// 	return (ft_putnbr(va_arg(format->args, int)));
	// else if (s[i] == 'u')
	// 	return (ft_putnbr(va_arg(format->args, unsigned int)));
	// else if (s[i] == 'x')
	// 	return (ft_puthex());
	// else if (s[i] == 'X')
	// 	return (ft_puthex());
	// else if (s[i] == 'p')
	// 	return ();
}

t_printf	*ft_init_list(void)
{
	t_printf	*format;

	format = malloc(sizeof(t_printf));
	if (!format)
		return (0);
	format->left_justify = 0;
	format->zero_pads = 0;
	format->sign = 0;
	format->blank = 0;
	format->hashtag = 0;
	format->period = 0;
	format->width_min = 0;
	format->width_max = 0;
	format->str_len = 0;
	format->int_len = 0;
	format->total = 0;
	return (format);
}

int	ft_printf(const char *s, ...)
{
	int	i;
	t_printf	*format;

	// if (!ft_check_flags(s))
	// 	return (write(1, "Wrong combination/number of flags\n", 34), -1);
	format = ft_init_list();
	va_start(format->args, s);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			i = i + ft_flags(&s[i], format);
			ft_conversions(&s[i], format);
		}
		else
			write(1, &s[i], 1);
		i++;
	}
	va_end(format->args);
	return (i);
}

int	main(void)
{
	ft_printf("ft_printf:%6.4s\n", "he");
	printf("printf:%6.4s\n", "he");
}