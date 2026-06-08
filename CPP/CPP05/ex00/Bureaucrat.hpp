#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <string>
# include <exception>

class Bureaucrat
{
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &);
		Bureaucrat &operator=(const Bureaucrat &);
		std::string getName(void);
		int getGrade(void);
		void incrementGrade(void);
		void decrementGrade(void);
		~Bureaucrat(void);

		class GradeTooLowException : public std::exception
		{
			public:
				GradeTooLowException(void);
				GradeTooLowException(std::string message);
				std::string message;
				virtual const char *what() const throw();
		};

		class GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException(void);
				GradeTooHighException(std::string message);
				std::string message;
				virtual const char *what() const throw();
		};

	private:
		const std::string _name;
		int _grade;
};

std::ostream& operator<<(std::ostream&, const Bureaucrat&);

#endif
