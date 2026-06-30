/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 21:53:52 by rafasant          #+#    #+#             */
/*   Updated: 2026/06/30 15:37:21 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

static void separator(std::string title)
{
    std::cout << "\n========== " << title
              << " ==========\n" << std::endl;
}

int main(void)
{
	separator("VALID CONSTRUCTION");

    try
    {
		ShrubberyCreationForm shrubbery("Shrubbery");
		RobotomyRequestForm robotomy("Robotomy");
		PresidentialPardonForm presidential("Presidential");
        std::cout << shrubbery << std::endl;
        std::cout << robotomy << std::endl;
        std::cout << presidential << std::endl;
    }
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

    separator("COPY CONSTRUCTOR");

    try
    {
		ShrubberyCreationForm original("Shrubbery");
		ShrubberyCreationForm copy(original);

        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy    : " << copy << std::endl;
    }
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
    {
		RobotomyRequestForm original("Robotomy");
		RobotomyRequestForm copy(original);

        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy    : " << copy << std::endl;
    }
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
    {
		PresidentialPardonForm original("Presidential");
		PresidentialPardonForm copy(original);

        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy    : " << copy << std::endl;
    }
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

    separator("ASSIGNMENT OPERATOR");

    try
    {
		ShrubberyCreationForm first("FirstShrubbery");
		ShrubberyCreationForm second("SecondShrubbery");

        std::cout << "Before assignment:" << std::endl;
        std::cout << first << std::endl;
        std::cout << second << std::endl;

        first = second;

        std::cout << "\nAfter assignment:" << std::endl;
        std::cout << first << std::endl;
        std::cout << second << std::endl;
    }
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
    {
		RobotomyRequestForm first("FirstRobotomy");
		RobotomyRequestForm second("SecondRobotomy");

        std::cout << "Before assignment:" << std::endl;
        std::cout << first << std::endl;
        std::cout << second << std::endl;

        first = second;

        std::cout << "\nAfter assignment:" << std::endl;
        std::cout << first << std::endl;
        std::cout << second << std::endl;
    }
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
    {
		PresidentialPardonForm first("FirstPresidential");
		PresidentialPardonForm second("SecondPresidential");

        std::cout << "Before assignment:" << std::endl;
        std::cout << first << std::endl;
        std::cout << second << std::endl;

        first = second;

        std::cout << "\nAfter assignment:" << std::endl;
        std::cout << first << std::endl;
        std::cout << second << std::endl;
    }
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

    separator("SELF ASSIGNMENT");

    try
    {
		ShrubberyCreationForm self("Self");

		ShrubberyCreationForm &ref = self;
		self = ref;
		
		std::cout << self << std::endl;
    }
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
    {
		RobotomyRequestForm self("Self");

		RobotomyRequestForm &ref = self;
		self = ref;
		
		std::cout << self << std::endl;
    }
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
    {
		PresidentialPardonForm self("Self");

		PresidentialPardonForm &ref = self;
		self = ref;
		
		std::cout << self << std::endl;
    }
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	separator("FORM SIGNING");

	try
	{
		Bureaucrat shrubberyBureaucrat("Shrubbery Bureaucrat", 135);
		Bureaucrat robotomyBureaucrat("Robotomy Bureaucrat", 40);
		Bureaucrat presidentialBureaucrat("Presidential Bureaucrat", 1);

		ShrubberyCreationForm shrubberyForm("Presidential Form");
		RobotomyRequestForm robotomyForm("Presidential Form");
		PresidentialPardonForm presidentialForm("Presidential Form");
		
		shrubberyBureaucrat.signForm(shrubberyForm);
		std::cout << shrubberyForm << std::endl;

		robotomyBureaucrat.signForm(robotomyForm);
		std::cout << robotomyForm << std::endl;
		
		presidentialBureaucrat.signForm(presidentialForm);
		std::cout << presidentialForm << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "GradeTooHighException thrown: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "GradeTooLowException thrown: " << e.what() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	separator("FORM EXECUTING");

	try
	{
		Bureaucrat shrubberyBureaucrat("Shrubbery Bureaucrat", 135);
		Bureaucrat robotomyBureaucrat("Robotomy Bureaucrat", 40);
		Bureaucrat presidentialBureaucrat("Presidential Bureaucrat", 1);

		ShrubberyCreationForm shrubberyForm("Presidential Form");
		RobotomyRequestForm robotomyForm("Presidential Form");
		PresidentialPardonForm presidentialForm("Presidential Form");
		
		shrubberyBureaucrat.executeForm(shrubberyForm);
		std::cout << shrubberyForm << std::endl;

		robotomyBureaucrat.executeForm(robotomyForm);
		std::cout << robotomyForm << std::endl;
		
		presidentialBureaucrat.executeForm(presidentialForm);
		std::cout << presidentialForm << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "GradeTooHighException thrown: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "GradeTooLowException thrown: " << e.what() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

    separator("END");

    return 0;
}
