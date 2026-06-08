#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	std::cout << "Default constructor called" << std::endl;
	if (grade < 1)
		throw new Bureaucrat::GradeTooHighException("Grade is too high. Maximum grade is 1.");
	else if (grade > 150)
		throw new Bureaucrat::GradeTooLowException("Grade is too low. Minimum grade is 150.");
	this->_name = name;
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
		this->_name = bureaucrat.getName();
		this->_grade = bureaucrat.getGrade();
	}
	return (*this);
}

std::string Bureaucrat::getName(void)
{
	return this->_name;
}

int Bureaucrat::getGrade(void)
{
	return this->_grade;
}

void Bureaucrat::incrementGrade(void)
{
	if (_grade - 1 < 1)
		throw new Bureaucrat::GradeTooHighException("Failed incrementing the grade. Maximum grade is 1.");
	_grade--;
}

void Bureaucrat::decrementGrade(void)
{
	if (_grade + 1 > 150)
		throw new Bureaucrat::GradeTooLowException("Failed decrementing the grade. Minimum grade is 150.");
	_grade++;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Destructor called" << std::endl;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(void)
{
	this->message = "";
}

Bureaucrat::GradeTooLowException::GradeTooLowException(std::string message)
{
	this->message = message;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(void)
{
	this->message = "";
}

Bureaucrat::GradeTooHighException::GradeTooHighException(std::string message)
{
	this->message = message;
}

std::ostream &operator<<(std::ostream &ostream, const Bureaucrat& bureaucrat)
{
	ostream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (ostream);
}
