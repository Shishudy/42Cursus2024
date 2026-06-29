/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 21:53:03 by rafasant          #+#    #+#             */
/*   Updated: 2026/06/29 21:48:40 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include <iostream>
# include <string>
# include <exception>
# include <cstdlib>
# include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &);
		std::string getTarget(void) const;
		void actualExecute(void) const;
		~RobotomyRequestForm(void);

	private:
		std::string _target;
};

std::ostream& operator<<(std::ostream&, const RobotomyRequestForm&);

#endif
