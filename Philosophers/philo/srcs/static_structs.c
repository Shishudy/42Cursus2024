/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_structs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:21:45 by rafasant          #+#    #+#             */
/*   Updated: 2025/08/07 20:00:28 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_context	*context(void)
{
	static t_context	philos;

	return (&philos);
}
