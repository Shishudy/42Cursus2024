#include "Bureaucrat.hpp"

int main(void)
{
	std::srand(150);
	int grade = 1;
	Bureaucrat bureaucrat("James " + std::to_string(grade), grade);

	while (1)
	{
		try
		{
			std::cout << bureaucrat;
			
			int i = 200;
			while (i > 0)
			{
				bureaucrat.incrementGrade();
				i--;
			}
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << "GradeTooHighException thrown: " << e.message << " | " << e.what() << std::endl;
			std::cout << bureaucrat;
			continue;
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "GradeTooLowException thrown: " <<  e.message << " | " << e.what() << std::endl;
			std::cout << bureaucrat;
			continue;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
			return (1);
		}

		break;
	}

	std::cout << bureaucrat;

	return (0);
}
