/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:08:43 by rafasant          #+#    #+#             */
/*   Updated: 2025/12/16 18:49:53 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	int		i;
    Zombie	*horde = new Zombie[N];

	if (N <= 0)
		return (NULL);
	i = 0;
	while (i < N)
	{
		horde[i].SetName(name);
		i++;
	}
    return (horde);
}
