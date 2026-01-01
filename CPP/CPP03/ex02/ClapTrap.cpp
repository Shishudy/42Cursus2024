/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:52:42 by rafasant          #+#    #+#             */
/*   Updated: 2025/12/29 13:49:45 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = clapTrap;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this != &clapTrap)
	{
		this->_name = clapTrap._name;
		this->_hitPoints = clapTrap._hitPoints;
		this->_energyPoints = clapTrap._energyPoints;
		this->_attackDamage = clapTrap._attackDamage;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints == 0)
		std::cout << "ClapTrap " << this->_name << " is down and can't attack!" << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << "ClapTrap " << this->_name << " does not have enough energy to attack!" << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is already down!" << std::endl;
	}
	else if (amount >= (unsigned int)this->_hitPoints)
	{
		this->_hitPoints = 0;
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " damage, setting their Hit Points to " << this->_hitPoints << "!" << std::endl;
	}
	else
	{
		this->_hitPoints -= amount;
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " damage, setting their Hit Points to " << this->_hitPoints << "!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 0)
		std::cout << "ClapTrap " << this->_name << " is down and can't repair themselves!" << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << "ClapTrap " << this->_name << " does not have enough energy to repair themselves!" << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->_name << " is repairing for " << amount << " Hit Points, setting their Hit Points to " << this->_hitPoints + amount << "!" << std::endl;
		this->_energyPoints--;
		this->_hitPoints += amount;
	}
}

void ClapTrap::showHitPoints(void)
{
	std::cout << "ClapTrap " << this->_name << " has " << this->_hitPoints << " Hit Points!" << std::endl;
}

void ClapTrap::showEnergy(void)
{
	std::cout << "ClapTrap " << this->_name << " has " << this->_energyPoints << " Energy Points!" << std::endl;
}

void ClapTrap::showAttackDamage(void)
{
	std::cout << "ClapTrap " << this->_name << " has " << this->_attackDamage << " Attack Damage!" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called" << std::endl;
}