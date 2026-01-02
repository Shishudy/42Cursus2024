/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 17:32:20 by rafasant          #+#    #+#             */
/*   Updated: 2026/01/02 17:34:15 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void)
{
	std::cout << "Character default constructor called" << std::endl;
}

Character::Character(const Character &other)
{
	std::cout << "Character copy constructor called" << std::endl;
	*this = other;
}

Character &Character::operator=(const Character &other)
{
	std::cout << "Character copy assignment operator called" << std::endl;
	if (this != &other)
	{
		// Copy your members here (deep copy if you own heap memory)
	}
	return *this;
}

Character::~Character(void)
{
	std::cout << "Character destructor called" << std::endl;
}

