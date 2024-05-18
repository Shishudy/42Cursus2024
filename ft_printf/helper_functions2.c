/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:04:42 by rafasant          #+#    #+#             */
/*   Updated: 2024/05/17 15:36:47 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long int n, char *base_to) //tentar fazer sem malloc, printar direto
{
	unsigned long int	base_len;
	int					str_len;
	char				*str;

	base_len = ft_strlen(base_to);
	str_len = ft_new_str_len(n, base_len);
	printf("STR_LEN: %d\n", str_len);
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