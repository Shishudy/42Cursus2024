/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 17:13:53 by rafasant          #+#    #+#             */
/*   Updated: 2026/01/02 17:41:23 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type)
{
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &other)
{
	std::cout << "AMateria copy constructor called" << std::endl;
	*this = other;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	std::cout << "AMateria copy assignment operator called" << std::endl;
	if (this != &other)
	{
		// Copy your members here (deep copy if you own heap memory)
	}
	return *this;
}

std::string const & AMateria::getType() const
{

}

AMateria::~AMateria(void)
{
	std::cout << "AMateria destructor called" << std::endl;
}

