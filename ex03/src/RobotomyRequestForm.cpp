#include "../inc/RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm():AForm("RobotomyRequestForm", 72, 45),_target("target"){
}

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

void	RobotomyRequestForm::doExec() const{
	
	srand(time(NULL));
	int x = rand() % 2;

	if (x)
		std::cout << "Vrrrrr! " << _target << " has been robotomized." << std::endl;
	else
		std::cout << "Robotomy failed." << std::endl;
}