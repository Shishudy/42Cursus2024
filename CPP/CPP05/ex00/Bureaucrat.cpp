/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 21:53:15 by rafasant          #+#    #+#             */
/*   Updated: 2026/06/29 19:04:39 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	std::cout << "Default constructor called" << std::endl;
	if (grade < 1)
		throw GradeTooHighException("Grade is too high. Maximum grade is 1.");
	else if (grade > 150)
		throw GradeTooLowException("Grade is too low. Minimum grade is 150.");
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = bureaucrat;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &bureaucrat)
	{
		this->_grade = bureaucrat.getGrade();
	}
	return (*this);
}

const std::string &Bureaucrat::getName(void) const
{
	return this->_name;
}

int Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

void Bureaucrat::incrementGrade(void)
{
	if (_grade - 1 < 1)
		throw GradeTooHighException("Failed incrementing the grade. Maximum grade is 1.");
	_grade--;
}

void Bureaucrat::decrementGrade(void)
{
	if (_grade + 1 > 150)
		throw GradeTooLowException("Failed decrementing the grade. Minimum grade is 150.");
	_grade++;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Destructor called" << std::endl;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(void)
{
	this->message = "Grade too low.";
}

Bureaucrat::GradeTooLowException::GradeTooLowException(std::string message)
{
	this->message = message;
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return this->message.c_str();
}

Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw()
{
	std::cout << "Destructor called" << std::endl;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(void)
{
	this->message = "Grade too high.";
}

Bureaucrat::GradeTooHighException::GradeTooHighException(std::string message)
{
	this->message = message;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return this->message.c_str();
}

Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw()
{
	std::cout << "Destructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &ostream, const Bureaucrat& bureaucrat)
{
	ostream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (ostream);
}
