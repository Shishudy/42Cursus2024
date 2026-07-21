/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 21:53:33 by rafasant          #+#    #+#             */
/*   Updated: 2026/07/21 15:58:40 by rafasant         ###   ########.fr       */
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
	const FormsDictionary	dict[4] = {{"Shrubbery", &ShrubberyCreationForm::ShrubberyCreationForm}, {"Robotomy", &RobotomyRequestForm::RobotomyRequestForm}, {"Presidential", &PresidentialPardonForm::PresidentialPardonForm}};
	
	// AForm *form = dict[name]->form

	int	i;

	i = 0;
	while (i < 4)
	{
		if (!dict[i].name.compare(name))
		{
			return (*dict[i].function)(target);
		}
		i++;
	}
}

Intern::~Intern(void)
{
	std::cout << "Intern destructor called" << std::endl;
}
