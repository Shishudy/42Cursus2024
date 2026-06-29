/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 21:53:03 by rafasant          #+#    #+#             */
/*   Updated: 2026/06/29 19:24:11 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form(std::string name, int signGrade, int executeGrade);
		Form(const Form &);
		Form &operator=(const Form &);
		const std::string &getName(void) const;
		int getSignGrade(void) const;
		int getExecuteGrade(void) const;
		bool getSigned(void) const;
		void beSigned(const Bureaucrat *);
		~Form(void);

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

std::ostream& operator<<(std::ostream&, const Form&);

#endif
