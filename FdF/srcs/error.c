/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:48:32 by rafasant          #+#    #+#             */
/*   Updated: 2025/01/06 16:12:03 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

void	ft_free(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	if (array)
		free(array);
}

void	deallocate(t_bag *bag)
{
	int	i;

	i = 0;
	if (bag->map)
	{
		while (bag->map[i])
			free(bag->map[i++]);
		free(bag->map);
	}
	if (bag->og_wf)
	{
		free(bag->og_wf->canva);
		free(bag->og_wf);
	}
	if (bag->mod_wf)
	{
		free(bag->mod_wf->canva);
		free(bag->mod_wf);
	}
	if (bag->mlx)
	{
		free(bag->mlx->mlx_ptr);
		free(bag->mlx);
	}
	if (bag)
		free(bag);
	exit(0);
}
