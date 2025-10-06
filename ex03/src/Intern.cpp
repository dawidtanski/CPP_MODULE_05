#include "../inc/Intern.hpp"
#include "../inc/AForm.hpp"

Intern::Intern(){
}

Intern::~Intern(){
}

Intern::Intern(const Intern& other){
}

Intern& Intern::operator=(const Intern& other){
	return *this;
}

AForm*	Intern::makeForm(std::string formName, std::string target){

	std::cout << "Intern creates " << formName << std::endl;

	return 
}