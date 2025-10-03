#pragma once
#include <iostream>
#include <fstream>
#include <exception>

class Bureaucrat;

class Form{

		private:
			const std::string _name;
			bool	_signed;
			const int _gradeToSign;
			const int _gradeToExec;

		public:
			Form();
			~Form();
			Form(const Form& other);
			Form& operator=(const Form& other);

			void beSigned(const Bureaucrat& bur);
			bool getSigned() const;
			const std::string getName() const;
			int getGradeToSign() const;
			int getGradeToExec() const;
			
			class GradeTooHighException : public std::exception{
				public:
					const char* what() const throw();
			};
			
			class GradeTooLowException : public std::exception{
				public:
					const char* what() const throw();
			};
};

std::ostream& operator<<(std::ostream& os, const Form& f);