/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 09:58:09 by rafasant          #+#    #+#             */
/*   Updated: 2025/12/17 12:13:34 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
}

void	Weapon::setType(std::string newType)
{
	this->type = newType;
}

const std::string	&Weapon::getType(void) const
{
	return (this->type);
}

Weapon::~Weapon(void)
{
	
}