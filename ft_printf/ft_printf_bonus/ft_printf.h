/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:44:25 by rafasant          #+#    #+#             */
/*   Updated: 2024/04/28 15:44:25 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft/libft.h"
#include <stdarg.h>

typedef struct	s_printf
{                        
    va_list	args;			// arg to print out
    int		left_justify;	// -
    int		zero_pads;		// zero padding
    int		sign;			// add + before number
    int		blank;			// space flag ' '
	int		hashtag;		// 0x or 0X before hex
    int		period;			// .
    int		width_min;		// width min
	int		width_max;		// width max
	int		str_len;		// len of str
	int		int_len;		// len of int
    int		is_zero;		// is number zero
	//int		perc;			// %
    int		total;			// return int
}	t_printf;

int		ft_printf(const char *s, ...);
void	ft_putchar(char c, t_printf *format);
void	ft_putstr(const char *s, t_printf *format);
void	ft_putnbr(int n, t_printf *format);
void	ft_handle_precision(t_printf *format);

#endif