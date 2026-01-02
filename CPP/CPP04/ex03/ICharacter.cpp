/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:17:37 by rafasant          #+#    #+#             */
/*   Updated: 2026/01/02 18:17:44 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

ICharacter::ICharacter(void)
{
	std::cout << "ICharacter default constructor called" << std::endl;
}

ICharacter::ICharacter(const ICharacter &other)
{
	std::cout << "ICharacter copy constructor called" << std::endl;
	*this = other;
}

ICharacter &ICharacter::operator=(const ICharacter &other)
{
	std::cout << "ICharacter copy assignment operator called" << std::endl;
	if (this != &other)
	{
		// Copy your members here (deep copy if you own heap memory)
	}
	return *this;
}

ICharacter::~ICharacter(void)
{
	std::cout << "ICharacter destructor called" << std::endl;
}

