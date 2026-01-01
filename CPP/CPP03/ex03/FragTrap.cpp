/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 16:52:46 by rafasant          #+#    #+#             */
/*   Updated: 2026/01/01 19:36:55 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->_hitPoints = FragTrap::defaultHitPoints;
	this->_energyPoints = FragTrap::defaultEnergyPoints;
	this->_attackDamage = FragTrap::defaultAttackDamage;
}

FragTrap::FragTrap(const FragTrap &FragTrap) : ClapTrap(FragTrap)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &FragTrap)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &FragTrap)
	{
		ClapTrap::operator=(FragTrap);
	}
	return *this;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << " holds out their hand for a high-five!" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called" << std::endl;
}