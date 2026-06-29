/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 21:53:03 by rafasant          #+#    #+#             */
/*   Updated: 2026/06/29 21:48:34 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP
# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm(std::string name, int signGrade, int executeGrade);
		AForm(const AForm &);
		AForm &operator=(const AForm &);
		const std::string &getName(void) const;
		int getSignGrade(void) const;
		int getExecuteGrade(void) const;
		bool getSigned(void) const;
		void beSigned(const Bureaucrat *);
		void execute(Bureaucrat const & executor) const;
		virtual void actualExecute(void) const = 0;
		virtual ~AForm(void) = 0;

		class GradeTooLowException : public std::exception
		{
			public:
				GradeTooLowException(void);
				GradeTooLowException(std::string message);
				std::string message;
				virtual const char *what() const throw();
				~GradeTooLowException(void) throw();
		};

		class GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException(void);
				GradeTooHighException(std::string message);
				std::string message;
				virtual const char *what() const throw();
				~GradeTooHighException(void) throw();
		};

	private:
		const std::string _name;
		const int _signGrade;
		const int _executeGrade;
		bool _signed;
};

std::ostream& operator<<(std::ostream&, const AForm&);

#endif
