#pragma once

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm: public AForm{

	private:
		std::string _target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& target);
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm &other);

		void	doExec() const;
};