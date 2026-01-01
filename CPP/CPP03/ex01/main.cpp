/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:54:27 by rafasant          #+#    #+#             */
/*   Updated: 2026/01/01 16:45:46 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
    int         i;
    ScavTrap    st1("ST1");
    ScavTrap    st2("ST2");

    st1.showHitPoints();
    st1.showEnergy();
    st1.showAttackDamage();
    st2.showHitPoints();
    st2.showEnergy();
    st2.showAttackDamage();
    std::cout << std::endl;
    i = 0;
    while (i < 5)
    {
        st1.attack("ST2");
        st2.takeDamage(20);
        i++;
    }
    std::cout << std::endl;
    st2.beRepaired(10);
    st2.attack("ST1");
    st1.takeDamage(20);
    std::cout << std::endl;
    st1.guardGate();
    std::cout << std::endl;
    ScavTrap st3(st1);
    st3.showHitPoints();
    st3.showEnergy();
    st3.showAttackDamage();
    return (0);
}
