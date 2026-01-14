/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 12:15:37 by rafasant          #+#    #+#             */
/*   Updated: 2026/01/14 15:09:40 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default constructor called" << std::endl;
	for(int i = 0; i < 100; i++)
	{
		this->_ideas[i] = "some string";
	}
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = other;
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &other)
	{
		for(int i = 0; i < 100; i++)
			this->_ideas[i] = other._ideas[i];
	}
	return *this;
}

std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index <= 99)
		return (this->_ideas[index]);
	return ("");
}

void Brain::setIdea(int index, const std::string &idea)
{
	if (index >= 0 && index <= 99)
		this->_ideas[index] = idea;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}