/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 21:53:33 by rafasant          #+#    #+#             */
/*   Updated: 2026/06/22 22:02:01 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string name, int signGrade, int executeGrade) : _name(name), _signGrade(signGrade), _executeGrade(executeGrade)
{
	std::cout << "Default constructor called" << std::endl;
	if (signGrade < 1)
		throw GradeTooHighException("Sign Grade is too high. Maximum grade is 1.");
	else if (signGrade > 150)
		throw GradeTooLowException("Sign Grade is too low. Minimum grade is 150.");
	if (executeGrade < 1)
		throw GradeTooHighException("Execute Grade is too high. Maximum grade is 1.");
	else if (executeGrade > 150)
		throw GradeTooLowException("Execute Grade is too low. Minimum grade is 150.");
}

Form::Form(const Form &form)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = form;
}

Form &Form::operator=(const Form &form)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &form)
	{
	}
	return (*this);
}

const std::string &Form::getName(void) const
{
	return this->_name;
}

int Form::getGrade(void) const
{
	return this->_grade;
}

void Form::incrementGrade(void)
{
	if (_grade - 1 < 1)
		throw GradeTooHighException("Failed incrementing the grade. Maximum grade is 1.");
	_grade--;
}

void Form::decrementGrade(void)
{
	if (_grade + 1 > 150)
		throw GradeTooLowException("Failed decrementing the grade. Minimum grade is 150.");
	_grade++;
}

Form::~Form(void)
{
	std::cout << "Destructor called" << std::endl;
}

Form::GradeTooLowException::GradeTooLowException(void)
{
	this->message = "";
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
	std::cout << "Destructor called" << std::endl;
}

Form::GradeTooHighException::GradeTooHighException(void)
{
	this->message = "";
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
	std::cout << "Destructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &ostream, const Form& form)
{
	ostream << form.getName() << ", form grade " << form.getGrade() << ".";
	return (ostream);
}
