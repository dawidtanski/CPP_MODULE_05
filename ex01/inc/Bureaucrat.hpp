#pragma once

#include <iostream>
#include <fstream>
#include "Form.hpp"

class Bureaucrat{
	
	private:
			const std::string _name;
			int	_grade;
	public:
			Bureaucrat(const std::string& name, int grade);
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

			void	signForm(Form& f) const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);