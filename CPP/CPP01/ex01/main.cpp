/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 20:52:16 by rafasant          #+#    #+#             */
/*   Updated: 2025/12/16 18:44:31 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int     i;
    int     n;
    Zombie  *horde;

    n = 5;
    horde = zombieHorde(n, "Zombie");
    if (!horde)
        return (1);
    i = 0;
    while (i < 5)
    {
        horde[i].announce();
        i++;
    }
    delete[] horde;
    return (0);
}