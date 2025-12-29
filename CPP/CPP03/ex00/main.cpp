/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:54:27 by rafasant          #+#    #+#             */
/*   Updated: 2025/12/29 17:40:42 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    int         i;
    ClapTrap    ct1("CT1");
    ClapTrap    ct2("CT2");

    ct1.showHitPoints();
    ct1.showEnergy();
    ct1.showAttackDamage();
    ct2.showHitPoints();
    ct2.showEnergy();
    ct2.showAttackDamage();
    
    std::cout << std::endl;
    i = 0;
    while (i < 9)
    {
        ct1.attack("CT2");
        ct2.takeDamage(1);
        i++;
    }
    ct2.beRepaired(1);
    ct2.attack("CT1");
    ct1.takeDamage(1);
    ct1.beRepaired(1);
    ct2.attack("CT1");
    ct1.takeDamage(1);
    ct1.beRepaired(1);
    ct1.attack("CT2");
    ClapTrap    ct3(ct1);
    ct3.showHitPoints();
    ct3.showEnergy();
    ct3.showAttackDamage();
    return (0);
}
