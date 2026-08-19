/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 21:53:33 by rafasant          #+#    #+#             */
/*   Updated: 2026/08/19 17:10:44 by rafasant         ###   ########.fr       */
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
	const FormsDictionary	dict[3] = {{"Shrubbery", &Intern::createShrubbery}, {"Robotomy", &Intern::createRobotomy}, {"Presidential", &Intern::createPresidential}};
	AForm *form;
	int	i;

	i = 0;
	while (i < 3)
	{
		if (!dict[i].name.compare(name))
		{
			form = (this->*dict[i].function)(target);
			std::cout << "Intern creates " << name << std::endl;
			return form;
		}
		i++;
	}
	std::cout << "Intern couldn't create " << name << " form because it doesn't exist." << std::endl;
    return NULL;
}

AForm *Intern::createShrubbery(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomy(std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidential(std::string target)
{
    return new PresidentialPardonForm(target);
}

Intern::~Intern(void)
{
	std::cout << "Intern destructor called" << std::endl;
}
