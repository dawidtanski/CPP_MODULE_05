#include "../inc/Intern.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

Intern::Intern(){
}

Intern::~Intern(){
}

Intern::Intern(const Intern& other){
	(void)other;
}

Intern& Intern::operator=(const Intern& other){
	(void)other;
	return *this;
}

AForm* Intern::createShrubberyForm(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyForm(const std::string& target) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialForm(const std::string& target) {
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string formName, std::string target) {
	FormCreator creators[] = {
		{"shrubbery creation", createShrubberyForm},
		{"robotomy request", createRobotomyForm},
		{"presidential pardon", createPresidentialForm}
	};

	for (size_t i = 0; i < sizeof(creators) / sizeof(creators[0]); ++i) {
		if (creators[i].name == formName) {
			std::cout << "Intern creates " << formName << std::endl;
			return creators[i].creator(target);
		}
	}

	throw FormNotFoundException();
}

const char* Intern::FormNotFoundException::what() const throw() {
	return "Form not found";
}