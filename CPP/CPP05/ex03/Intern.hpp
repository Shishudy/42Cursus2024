/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 21:53:03 by rafasant          #+#    #+#             */
/*   Updated: 2026/08/19 16:56:59 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>
# include <string>
# include <exception>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(const Intern &);
		Intern &operator=(const Intern &);
		AForm *makeForm(std::string, std::string);
		~Intern(void);

	private:
		AForm *createShrubbery(std::string);
		AForm *createRobotomy(std::string);
		AForm *createPresidential(std::string);
};

struct FormsDictionary
{
	std::string name;
	AForm *(Intern::*function)(std::string);
};

#endif
