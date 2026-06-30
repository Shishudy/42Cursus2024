/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 21:53:33 by rafasant          #+#    #+#             */
/*   Updated: 2026/06/29 22:27:19 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequest", 72, 45)
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
	_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &form) : AForm(form)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	*this = form;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &form)
{
	std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
	if (this != &form)
	{
	}
	return (*this);
}

std::string RobotomyRequestForm::getTarget(void) const
{
	return this->_target;
}

void RobotomyRequestForm::actualExecute(void) const
{
	std::cout << "*starts doing drilling noises...*" << std::endl;

	if (rand() % 2 == 0)
		std::cout << this->_target << " has been robotomized." << std::endl;
	else
		std::cout << this->_target << "'s robotomy failed." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &ostream, const RobotomyRequestForm& form)
{
	ostream << "Form \"" << form.getName() << "\""
	<< "\n- Form sign grade: " << form.getSignGrade()
	<< "\n- Form execute grade: " << form.getExecuteGrade()
	<< "\n- Is Form signed: " << form.getSigned()
	<< "\n- Form target: " << form.getTarget();
	return (ostream);
}
