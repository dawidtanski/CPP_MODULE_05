#include "../inc/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target):AForm("RobotomyRequestForm", 72, 45),_target(target){
}

RobotomyRequestForm::~RobotomyRequestForm(){};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other):AForm(other), _target(other._target){
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other){
	if (this != &other){
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	std::cout << "Vrrrrr!  ";
}