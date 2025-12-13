/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 16:10:49 by rafasant          #+#    #+#             */
/*   Updated: 2025/12/13 17:47:47 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_char(char *info, char data)
{
	ft_printf("\n%s: >%c<\n", info, data);
}

void	print_string(char *info, char *data)
{
	ft_printf("\n%s: >%s<\n", info, data);
}

void	print_pointer(char *info, void *data)
{
	ft_printf("\n%s: >%p<\n", info, data);
}
