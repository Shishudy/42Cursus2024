/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 21:53:52 by rafasant          #+#    #+#             */
/*   Updated: 2026/06/29 20:12:24 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Form.hpp"
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
        Form form("Form", 42, 42);
        std::cout << form << std::endl;
    }
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

    separator("GRADE TOO HIGH IN CONSTRUCTOR");

    try
    {
        Form form("Form", 0, 0);
        std::cout << form << std::endl;
    }
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
    {
        Form form("Form", 1, 0);
        std::cout << form << std::endl;
    }
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

    separator("GRADE TOO LOW IN CONSTRUCTOR");

    try
    {
        Form form("Form", 1000, 1000);
        std::cout << form << std::endl;
    }
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
    {
        Form form("Form", 1, 1000);
        std::cout << form << std::endl;
    }
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

    separator("COPY CONSTRUCTOR");

    try
    {
		Form original("Form", 25, 25);
		Form copy(original);

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
        Form first("First", 100, 100);
        Form second("Second", 20, 20);

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
        Form self("Self", 50, 50);

		Form &ref = self;
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
		Bureaucrat canSign("A", 1);

		Bureaucrat cantSign("B", 149);

		Form form("Form", 42, 42);
		std::cout << form << std::endl;

		cantSign.signForm(form);
		std::cout << form << std::endl;
		
		canSign.signForm(form);
		std::cout << form << std::endl;
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
