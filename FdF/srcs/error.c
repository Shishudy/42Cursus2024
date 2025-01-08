/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:48:32 by rafasant          #+#    #+#             */
/*   Updated: 2025/01/08 16:38:28 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

int	close_window(t_bag *bag)
{
	mlx_destroy_image(bag->mlx->mlx_ptr, bag->og_wf->canva->img);
	if (bag->mod_wf)
		mlx_destroy_image(bag->mlx->mlx_ptr, bag->mod_wf->canva->img);
	mlx_destroy_window(bag->mlx->mlx_ptr, bag->mlx->win_ptr);
	mlx_destroy_display(bag->mlx->mlx_ptr);
	deallocate(bag);
	return (0);
}

void	reset_screen(t_bag *bag)
{
	if (!bag->mod_wf)
		return ;
	mlx_destroy_image(bag->mlx->mlx_ptr, bag->mod_wf->canva->img);
	free(bag->mod_wf->canva);
	free(bag->mod_wf);
	bag->mod_wf = NULL;
}

void	ft_free(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	if (array)
		free(array);
}

void	deallocate_mlx(t_bag *bag)
{
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
	deallocate_mlx(bag);
	if (bag)
		free(bag);
	exit(0);
}
