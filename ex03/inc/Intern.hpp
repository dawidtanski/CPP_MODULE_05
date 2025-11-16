#pragma once

#include <iostream>
#include <string>

class AForm;

class Intern{
	private:
	static AForm* createShrubberyForm(const std::string& target);
	static AForm* createRobotomyForm(const std::string& target);
	static AForm* createPresidentialForm(const std::string& target);

	struct	FormCreator{
		std::string name;
		AForm* (*creator)(const std::string&);
	};

	public:
		Intern();
		~Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);

		AForm* makeForm(std::string formName, std::string target);

		class FormNotFoundException : public std::exception{
			public:
				const char* what() const throw();
		};
};