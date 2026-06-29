/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 21:53:33 by rafasant          #+#    #+#             */
/*   Updated: 2026/06/29 20:17:37 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string name, int signGrade, int executeGrade) : _name(name), _signGrade(signGrade), _executeGrade(executeGrade)
{
	std::cout << "Form default constructor called" << std::endl;
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

Form::Form(const Form &form) : _name(form._name), _signGrade(form._signGrade), _executeGrade(form._executeGrade)
{
	std::cout << "Form copy constructor called" << std::endl;
	*this = form;
}

Form &Form::operator=(const Form &form)
{
	std::cout << "Form copy assignment operator called" << std::endl;
	if (this != &form)
	{
		this->_signed = false;
	}
	return (*this);
}

const std::string &Form::getName(void) const
{
	return this->_name;
}

int Form::getSignGrade(void) const
{
	return this->_signGrade;
}

int Form::getExecuteGrade(void) const
{
	return this->_executeGrade;
}

bool Form::getSigned(void) const
{
	return this->_signed;
}

void Form::beSigned(const Bureaucrat *bureaucrat)
{
	if (bureaucrat->getGrade() <= this->_signGrade)
	{
		this->_signed = true;
	}
	else
		throw GradeTooLowException("Bureaucrat Grade is too low.");
}

Form::~Form(void)
{
	std::cout << "Form destructor called" << std::endl;
}

Form::GradeTooLowException::GradeTooLowException(void)
{
	this->message = "Grade too low.";
}

Form::GradeTooLowException::GradeTooLowException(std::string message)
{
	this->message = message;
}

const char *Form::GradeTooLowException::what() const throw()
{
	return this->message.c_str();
}

Form::GradeTooLowException::~GradeTooLowException(void) throw()
{
	std::cout << "GradeTooLowException destructor called" << std::endl;
}

Form::GradeTooHighException::GradeTooHighException(void)
{
	this->message = "Grade too high.";
}

Form::GradeTooHighException::GradeTooHighException(std::string message)
{
	this->message = message;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return this->message.c_str();
}

Form::GradeTooHighException::~GradeTooHighException(void) throw()
{
	std::cout << "GradeTooHighException destructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &ostream, const Form& form)
{
	ostream << "Form \"" << form.getName() << "\""
	<< "\n- Form sign grade: " << form.getSignGrade()
	<< "\n- Form execute grade: " << form.getExecuteGrade()
	<< "\n- Is form signed: " << form.getSigned();
	return (ostream);
}
