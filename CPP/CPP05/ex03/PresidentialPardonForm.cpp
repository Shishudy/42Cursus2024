/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 21:53:33 by rafasant          #+#    #+#             */
/*   Updated: 2026/06/29 22:27:23 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardon", 25, 5)
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
	_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &form) : AForm(form)
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	*this = form;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &form)
{
	std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
	if (this != &form)
	{
	}
	return (*this);
}

std::string PresidentialPardonForm::getTarget(void) const
{
	return this->_target;
}

void PresidentialPardonForm::actualExecute(void) const
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &ostream, const PresidentialPardonForm& form)
{
	ostream << "Form \"" << form.getName() << "\""
	<< "\n- Form sign grade: " << form.getSignGrade()
	<< "\n- Form execute grade: " << form.getExecuteGrade()
	<< "\n- Is Form signed: " << form.getSigned()
	<< "\n- Form target: " << form.getTarget();
	return (ostream);
}
