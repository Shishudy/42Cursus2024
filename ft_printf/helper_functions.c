/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:31:20 by rafasant          #+#    #+#             */
/*   Updated: 2024/04/28 16:31:20 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, t_printf *format)
{
	unsigned char	c2;

	c2 = (unsigned char)c;
	write(1, &c2, 1);
	format->total++;
}

void	ft_handle_precision(t_printf *format)
{
	// if (s == 's')
	// {
	// 	while (format->width_min > format->width_max)
	// 	{
	// 		write(1, " ", 1);
	// 		format->total++;
	// 		format->width_min--;
	// 	}
	// }
	if (format->zero_pads == 0)
	{
		// while ((format->width_min - format->width_max > 0 && format->width_min > format->str_len) || (format->width_min  - format->width_max > format->str_len))
		// {
		// 	write(1, " ", 1);
		// 	format->total++;
		// 	format->width_min--;
		// }
		while (format->width_min > format->width_max || format->width_min > format->str_len)
		{
			write(1, " ", 1);
			format->total++;
			format->width_min--;
		}
	}
}

void	ft_putstr(const char *s, t_printf *format)
{
	int	i;

	if (!s)
	{
		format->total--;
		return ;
	}
	i = 0;
	while (s[i] != '\0')
	{
		if (format->period == 1 && i == format->width_max)
			break ;
		write(1, &s[i], 1);
		format->total++;
		i++;
	}
}

// int	ft_putptr(char *ptr)
// {
	
// }

void	ft_putnbr(int n, t_printf *format)
{
	char	*str;
	int		str_len;

	str = ft_itoa(n);
	str_len = ft_strlen(str);
	format->str_len = str_len;
	ft_handle_precision(format);
	if (n == 0 && format->period == 1 && format->width_max == 0)
		return ;
	if (format->width_max > str_len || (format->width_min > str_len && format->zero_pads == 1))
	{
		while (format->width_max > str_len || (format->width_min > str_len && format->zero_pads == 1))
		{
			write(1, "0", 1);
			str_len++;
		}
	}
	else
		format->width_max = str_len;
	ft_putstr(str, format);
}

void	ft_preprocessing()