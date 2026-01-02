/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:52:42 by rafasant          #+#    #+#             */
/*   Updated: 2025/12/29 13:49:45 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	_type = "Dog";
	_brain = new Brain();
}

Dog::Dog(const Dog &dog) : Animal(dog)
{
	std::cout << "Dog copy constructor called" << std::endl;
	_brain = new Brain(*dog._brain);
}

Dog &Dog::operator=(const Dog &dog)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &dog)
	{
		Animal::operator=(dog);
		*_brain = *dog._brain;
	}
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "Woof Woof!" << std::endl;
}

std::string Dog::getIdea(int index) const
{
	if (index >= 0 && index <= 99)
		return (this->_brain->getIdea(index));
	return ("");
}

void Dog::setIdea(int index, const std::string &idea)
{
	if (index >= 0 && index <= 99)
		this->_brain->setIdea(index, idea);
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}