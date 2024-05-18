/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:27:35 by rafasant          #+#    #+#             */
/*   Updated: 2024/05/18 12:26:40 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# include <limits.h>

int				ft_printf(const char *s, ...);
int				ft_check_format(va_list args, const char *s);
int				ft_putchar(char c);
int				ft_putstr(const char *s);
int				ft_itoa_base(long int n, char *base_to);
int				ft_new_str_len(long int n, int base_len);
int				ft_putptr(unsigned long int n, char *base_to);
size_t			ft_strlen(const char *str);

#endif