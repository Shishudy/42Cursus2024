/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 21:53:52 by rafasant          #+#    #+#             */
/*   Updated: 2026/06/30 19:52:58 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

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

		ShrubberyCreationForm shrubberyForm("Shrubbery Form");
		RobotomyRequestForm robotomyForm("Robotomy Form");
		PresidentialPardonForm presidentialForm("Presidential Form");
		
		shrubberyBureaucrat.signForm(shrubberyForm);
		std::cout << shrubberyForm << std::endl;

		robotomyBureaucrat.signForm(robotomyForm);
		std::cout << robotomyForm << std::endl;
		
		presidentialBureaucrat.signForm(presidentialForm);
		std::cout << presidentialForm << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	separator("FORM EXECUTING");

	try
	{
		separator("UNSIGNED FORM EXECUTING");

		Bureaucrat shrubberyBureaucrat("Shrubbery Bureaucrat", 135);
		Bureaucrat robotomyBureaucrat("Robotomy Bureaucrat", 40);
		Bureaucrat presidentialBureaucrat("Presidential Bureaucrat", 1);

		ShrubberyCreationForm shrubberyForm("Shrubbery Form");
		RobotomyRequestForm robotomyForm("Robotomy Form");
		PresidentialPardonForm presidentialForm("Presidential Form");
		
		shrubberyBureaucrat.executeForm(shrubberyForm);
		std::cout << shrubberyForm << std::endl;

		robotomyBureaucrat.executeForm(robotomyForm);
		std::cout << robotomyForm << std::endl;
		
		presidentialBureaucrat.executeForm(presidentialForm);
		std::cout << presidentialForm << std::endl;

		separator("SIGNED FORM EXECUTING");
		
		shrubberyBureaucrat.signForm(shrubberyForm);
		std::cout << shrubberyForm << std::endl;

		robotomyBureaucrat.signForm(robotomyForm);
		std::cout << robotomyForm << std::endl;
		
		presidentialBureaucrat.signForm(presidentialForm);
		std::cout << presidentialForm << std::endl;

		shrubberyBureaucrat.executeForm(shrubberyForm);
		std::cout << shrubberyForm << std::endl;

		robotomyBureaucrat.executeForm(robotomyForm);
		std::cout << robotomyForm << std::endl;
		
		presidentialBureaucrat.executeForm(presidentialForm);
		std::cout << presidentialForm << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	separator("INTERN TESTS");

	try
	{
		Intern intern;
		AForm *form1;
		AForm *form2;
		AForm *form3;
		AForm *form4;

		separator("VALID FORM CREATION");

		form1 = intern.makeForm("Shrubbery", "Garden");
		std::cout << *form1 << std::endl;
		delete form1;

		form2 = intern.makeForm("Robotomy", "Bender");
		std::cout << *form2 << std::endl;
		delete form2;

		form3 = intern.makeForm("Presidential", "Arthur Dent");
		std::cout << *form3 << std::endl;
		delete form3;

		separator("INVALID FORM CREATION");

		form4 = intern.makeForm("Invalid Form", "Target");
		if (form4)
		{
			std::cout << *form4 << std::endl;
			delete form4;
		}

		separator("INTERN CREATED FORM USAGE");

		Bureaucrat boss("Boss", 1);
		AForm *formToSign = intern.makeForm("Presidential", "Zaphod");
		
		if (formToSign)
		{
			std::cout << *formToSign << std::endl;
			boss.signForm(*formToSign);
			std::cout << *formToSign << std::endl;
			boss.executeForm(*formToSign);
			delete formToSign;
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

    separator("END");

    return 0;
}
