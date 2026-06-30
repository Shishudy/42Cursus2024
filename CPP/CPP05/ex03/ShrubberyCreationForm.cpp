/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 21:53:33 by rafasant          #+#    #+#             */
/*   Updated: 2026/06/30 20:10:00 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreation", 145, 137)
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &form) : AForm(form)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	*this = form;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &form)
{
	std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	if (this != &form)
	{
	}
	return (*this);
}

std::string ShrubberyCreationForm::getTarget(void) const
{
	return this->_target;
}

void ShrubberyCreationForm::actualExecute(void) const
{
	std::ofstream outFile((this->_target + "_shrubbery").c_str());
	std::string tree = "    *    \n   ***   \n  *****  \n    *    \n";
	outFile << tree;
	outFile.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &ostream, const ShrubberyCreationForm& form)
{
	ostream << "Form \"" << form.getName() << "\""
	<< "\n- Form sign grade: " << form.getSignGrade()
	<< "\n- Form execute grade: " << form.getExecuteGrade()
	<< "\n- Is Form signed: " << form.getSigned()
	<< "\n- Form target: " << form.getTarget();
	return (ostream);
}
