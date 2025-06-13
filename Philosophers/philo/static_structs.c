/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_structs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:21:45 by rafasant          #+#    #+#             */
/*   Updated: 2025/06/13 14:00:07 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philo	*philos(void)
{
	static t_philo	philos;

	return (&philos);
}

t_catch	*catch(void)
{
	static t_catch	catch;
	
	return (&catch);
}