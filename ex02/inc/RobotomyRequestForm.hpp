#pragma once

#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm: public AForm{

	private:
		std::string _target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& target);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm &other);

		void	doExec() const;
};