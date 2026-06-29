/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 21:53:52 by rafasant          #+#    #+#             */
/*   Updated: 2026/06/29 22:24:21 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

// static void separator(std::string title)
// {
//     std::cout << "\n========== " << title
//               << " ==========\n" << std::endl;
// }

int main(void)
{
	ShrubberyCreationForm form("home");
	form.actualExecute();
}
