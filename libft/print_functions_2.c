/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 16:10:49 by rafasant          #+#    #+#             */
/*   Updated: 2025/12/13 17:47:45 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_int(char *info, int data)
{
	ft_printf("\n%s: >%d<\n", info, data);
}

void	print_long(char *info, long data)
{
	printf("\n%s: >%ld<\n", info, data);
}

void	print_double(char *info, double data)
{
	printf("\n%s: >%f<\n", info, data);
}

void	print_float(char *info, float data)
{
	printf("\n%s: >%f<\n", info, data);
}
