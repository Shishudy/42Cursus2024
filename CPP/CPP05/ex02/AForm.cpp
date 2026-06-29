/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 21:53:33 by rafasant          #+#    #+#             */
/*   Updated: 2026/06/29 22:27:33 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string name, int signGrade, int executeGrade) : _name(name), _signGrade(signGrade), _executeGrade(executeGrade)
{
	std::cout << "AForm default constructor called" << std::endl;
	if (signGrade < 1)
		throw GradeTooHighException("Sign Grade is too high. Maximum grade is 1.");
	else if (signGrade > 150)
		throw GradeTooLowException("Sign Grade is too low. Minimum grade is 150.");
	if (executeGrade < 1)
		throw GradeTooHighException("Execute Grade is too high. Maximum grade is 1.");
	else if (executeGrade > 150)
		throw GradeTooLowException("Execute Grade is too low. Minimum grade is 150.");
	_signed = false;
}

AForm::AForm(const AForm &form) : _name(form._name), _signGrade(form._signGrade), _executeGrade(form._executeGrade)
{
	std::cout << "AForm copy constructor called" << std::endl;
	*this = form;
}

AForm &AForm::operator=(const AForm &form)
{
	std::cout << "AForm copy assignment operator called" << std::endl;
	if (this != &form)
	{
		this->_signed = false;
	}
	return (*this);
}

const std::string &AForm::getName(void) const
{
	return this->_name;
}

int AForm::getSignGrade(void) const
{
	return this->_signGrade;
}

int AForm::getExecuteGrade(void) const
{
	return this->_executeGrade;
}

bool AForm::getSigned(void) const
{
	return this->_signed;
}

void AForm::beSigned(const Bureaucrat *bureaucrat)
{
	if (bureaucrat->getGrade() <= this->_signGrade)
	{
		this->_signed = true;
	}
	else
		throw GradeTooLowException("Bureaucrat Grade is too low.");
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (this->_signed == false)
		throw ("Form not signed.");
	else if (executor.getGrade() > this->_executeGrade)
		throw GradeTooLowException("Bureaucrat Grade is too low.");

	actualExecute();
}

AForm::~AForm(void)
{
	std::cout << "AForm destructor called" << std::endl;
}

AForm::GradeTooLowException::GradeTooLowException(void)
{
	this->message = "Grade too low.";
}

AForm::GradeTooLowException::GradeTooLowException(std::string message)
{
	this->message = message;
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return this->message.c_str();
}

AForm::GradeTooLowException::~GradeTooLowException(void) throw()
{
	std::cout << "GradeTooLowException destructor called" << std::endl;
}

AForm::GradeTooHighException::GradeTooHighException(void)
{
	this->message = "Grade too high.";
}

AForm::GradeTooHighException::GradeTooHighException(std::string message)
{
	this->message = message;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return this->message.c_str();
}

AForm::GradeTooHighException::~GradeTooHighException(void) throw()
{
	std::cout << "GradeTooHighException destructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &ostream, const AForm& form)
{
	ostream << "Form \"" << form.getName() << "\""
	<< "\n- Form sign grade: " << form.getSignGrade()
	<< "\n- Form execute grade: " << form.getExecuteGrade()
	<< "\n- Is Form signed: " << form.getSigned();
	return (ostream);
}
