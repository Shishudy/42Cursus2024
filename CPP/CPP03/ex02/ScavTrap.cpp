/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 15:53:14 by rafasant          #+#    #+#             */
/*   Updated: 2026/01/01 16:36:55 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap) : ClapTrap(scavTrap)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &scavTrap)
	{
		ClapTrap::operator=(scavTrap);
	}
	return *this;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_hitPoints == 0)
		std::cout << "ScavTrap " << this->_name << " is down and can't attack!" << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << "ScavTrap " << this->_name << " does not have enough energy to attack!" << std::endl;
	else
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate Keeper mode!" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
}