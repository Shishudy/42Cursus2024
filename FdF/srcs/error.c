/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:48:32 by rafasant          #+#    #+#             */
/*   Updated: 2024/11/04 19:10:40 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

void	ft_free(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		ft_bzero(array[i], ft_strlen(array[i]));
		free(array[i++]);
	}
	if (array)
		free(array);
}

void	deallocate(t_bag *bag)
{
	int	i;

	i = 0;
	if (bag->mlx)
	{
		free(bag->mlx->mlx_ptr);
		free(bag->mlx);
	}
	if (bag->og_wf)
	{
		free(bag->og_wf->canva);
		free(bag->og_wf);
	}
	if (bag->curr_wf)
	{
		free(bag->curr_wf->canva);
		free(bag->curr_wf);
	}
	if (bag->map)
	{
		while (bag->map[i])
			free(bag->map[i++]);
		free(bag->map);
	}
	if (bag)
		free(bag);
	exit(0);
}
