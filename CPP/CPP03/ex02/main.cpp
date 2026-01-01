/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:54:27 by rafasant          #+#    #+#             */
/*   Updated: 2026/01/01 17:13:17 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	int			i;
	FragTrap	ft1("FT1");
	FragTrap	ft2("FT2");

	ft1.showHitPoints();
	ft1.showEnergy();
	ft1.showAttackDamage();
	ft2.showHitPoints();
	ft2.showEnergy();
	ft2.showAttackDamage();
	std::cout << std::endl;
	i = 0;
	while (i < 5)
	{
		ft1.attack("FT2");
		ft2.takeDamage(30);
		i++;
	}
	std::cout << std::endl;
	ft2.beRepaired(20);
	ft2.attack("FT1");
	ft1.takeDamage(30);
	std::cout << std::endl;
	ft1.highFivesGuys();
	std::cout << std::endl;
	FragTrap ft3(ft1);
	ft3.showHitPoints();
	ft3.showEnergy();
	ft3.showAttackDamage();
	return (0);
}
