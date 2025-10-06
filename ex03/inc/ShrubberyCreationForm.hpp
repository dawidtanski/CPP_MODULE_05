#pragma once

#include <iostream>
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm {
	private:
		std::string _target;
	public:
	ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other);

		void	doExec() const;
};