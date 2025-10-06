#pragma once

#include <iostream>

class AForm;

class Intern{

	public:
		Intern();
		~Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);

		AForm* makeForm(std::string formName, std::string target);
};