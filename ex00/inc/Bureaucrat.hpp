#pragma once

#include <iostream>
#include <fstream>

class Bureaucrat{
	
	private:
			const std::string _name;
			int	_grade;
	public:
			Bureaucrat(int grade);
			~Bureaucrat();
			Bureaucrat(const Bureaucrat& other);
			Bureaucrat& operator=(const Bureaucrat& other);

			class GradeTooHighException : public std::exception{
				public:
					const char* what() const throw();
			};

			class GradeTooLowException : public std::exception{
				public:
					const char* what() const throw();
			};

			const std::string	getName() const;
			int	getGrade() const;
			void	gradeUp();
			void	gradeDown();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);