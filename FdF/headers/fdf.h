/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:05:59 by rafasant          #+#    #+#             */
/*   Updated: 2024/10/09 19:40:55 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

typedef struct s_map
{
	int		axis; // x axis
	int		ordinate; // y axis
	int		altitude; // z axis
	int		colour; // colour code
}					t_map;

typedef struct s_bag
{
	t_map	**map;
	
}					t_bag;


#endif