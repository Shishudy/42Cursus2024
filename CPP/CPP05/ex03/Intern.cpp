/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 21:53:33 by rafasant          #+#    #+#             */
/*   Updated: 2026/06/30 20:23:42 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &intern)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = intern;
}

Intern &Intern::operator=(const Intern &intern)
{
	std::cout << "Intern copy assignment operator called" << std::endl;
	if (this != &intern)
	{
	}
	return (*this);
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	const LevelsDictionary	dict[4] = {{"DEBUG", &Harl::debug}, {"INFO", &Harl::info}, {"WARNING", &Harl::warning}, {"ERROR", &Harl::error}};
	if (name == "Robotomy")
		
	switch (name)
	{
		case name"Robotomy" : return new RobotomyRequestForm(target);
	}
}

Intern::~Intern(void)
{
	std::cout << "Intern destructor called" << std::endl;
}
