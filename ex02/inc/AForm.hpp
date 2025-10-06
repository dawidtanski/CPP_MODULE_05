#pragma once
#include <iostream>
#include <fstream>
#include <exception>

class Bureaucrat;

class AForm{

		private:
			const std::string _name;
			bool	_signed;
			const int _gradeToSign;
			const int _gradeToExec;

		public:
			AForm();
			AForm(const std::string name, int gradeToSign, int gradeToExec);
			virtual ~AForm();
			AForm(const AForm& other);
			AForm& operator=(const AForm& other);

			void beSigned(const Bureaucrat& bur);
			bool getSigned() const;
			const std::string getName() const;
			int getGradeToSign() const;
			int getGradeToExec() const;

			void execute(Bureaucrat const &executor) const;
		
		protected:
			virtual void doExec() const = 0;
			
			class GradeTooHighException : public std::exception{
				public:
					const char* what() const throw();
			};
			
			class GradeTooLowException : public std::exception{
				public:
					const char* what() const throw();
			};

			class FormNotSignedException : public std::exception{
				public:
					const char* what() const throw();
			};
};

std::ostream& operator<<(std::ostream& os, const AForm& f);