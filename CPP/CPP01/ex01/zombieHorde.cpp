/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:08:43 by rafasant          #+#    #+#             */
/*   Updated: 2026/01/07 18:26:09 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	int		i;
    Zombie	*horde;

	if (N <= 0)
		return (NULL);
	horde = new Zombie[N];
	i = 0;
	while (i < N)
	{
		horde[i].setName(name);
		i++;
	}
    return (horde);
}
