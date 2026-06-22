/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 21:07:47 by rafasant          #+#    #+#             */
/*   Updated: 2026/06/22 21:47:04 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

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
        Bureaucrat bob("Bob", 42);
        std::cout << bob << std::endl;
    }
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

    separator("GRADE TOO HIGH IN CONSTRUCTOR");

    try
    {
        Bureaucrat boss("Boss", 0);
        std::cout << boss << std::endl;
    }
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

    separator("GRADE TOO LOW IN CONSTRUCTOR");

    try
    {
        Bureaucrat intern("Intern", 151);
        std::cout << intern << std::endl;
    }
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

    separator("INCREMENT");

    try
    {
        Bureaucrat alice("Alice", 42);

        std::cout << "Before: " << alice << std::endl;

        alice.incrementGrade();

        std::cout << "After : " << alice << std::endl;
    }
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

    separator("DECREMENT");

    try
    {
        Bureaucrat john("John", 42);

        std::cout << "Before: " << john << std::endl;

        john.decrementGrade();

        std::cout << "After : " << john << std::endl;
    }
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

    separator("INCREMENT ABOVE LIMIT");

    try
    {
        Bureaucrat president("President", 1);

        std::cout << president << std::endl;

        president.incrementGrade();
    }
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

    separator("DECREMENT BELOW LIMIT");

    try
    {
        Bureaucrat trainee("Trainee", 150);

        std::cout << trainee << std::endl;

        trainee.decrementGrade();
    }
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

    separator("COPY CONSTRUCTOR");

    try
    {
        Bureaucrat original("Original", 25);
        Bureaucrat copy(original);

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
        Bureaucrat first("First", 100);
        Bureaucrat second("Second", 20);

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
        Bureaucrat self("Self", 50);

		Bureaucrat &ref = self;
		self = ref;
    }
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		// Bureaucrat a("A", 1);
		// a.incrementGrade();   // throws

		// Bureaucrat b("B", 150);
		// b.decrementGrade();   // throws

		// Bureaucrat c("C", 0);   // throws
		// Bureaucrat d("D", 151); // throws
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

// #include "Bureaucrat.hpp"

// int main(void)
// {
// 	std::srand(150);
// 	int grade = 1;
// 	Bureaucrat bureaucrat("James " + std::to_string(grade), grade);

// 	while (1)
// 	{
// 		try
// 		{
// 			std::cout << bureaucrat;
			
// 			int i = 200;
// 			while (i > 0)
// 			{
// 				bureaucrat.incrementGrade();
// 				i--;
// 			}
// 		}
// 		catch (const Bureaucrat::GradeTooHighException &e)
// 		{
// 			std::cerr << "GradeTooHighException thrown: " << e.message << " | " << e.what() << std::endl;
// 			std::cout << bureaucrat;
// 			continue;
// 		}
// 		catch (const Bureaucrat::GradeTooLowException &e)
// 		{
// 			std::cerr << "GradeTooLowException thrown: " <<  e.message << " | " << e.what() << std::endl;
// 			std::cout << bureaucrat;
// 			continue;
// 		}
// 		catch (const std::exception &e)
// 		{
// 			std::cerr << e.what() << std::endl;
// 			return (1);
// 		}

// 		break;
// 	}

// 	std::cout << bureaucrat;

// 	return (0);
// }