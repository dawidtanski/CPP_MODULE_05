#include "../inc/Bureaucrat.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/Intern.hpp"
#include <cstdlib>
#include <ctime>

int main(){
	srand(time(NULL));

	{
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		Bureaucrat official("Manager", 70);
		official.signForm(*rrf);
		delete rrf;  
	}

	try{
		Intern intern;
		Bureaucrat official_high("CEO", 1);  // High grade

		// Test 1: Create and sign ShrubberyCreationForm
		AForm* form2 = intern.makeForm("shrubbery creation", "home");
		official_high.signForm(*form2);
		delete form2;

		// Test 2: Create and sign PresidentialPardonForm
		AForm* form3 = intern.makeForm("presidential pardon", "Alice");
		official_high.signForm(*form3);
		delete form3;

		// Test 2.5: Create and sign PresidentialPardonForm
		AForm* form4 = intern.makeForm("robotomy request", "Tom");
		official_high.signForm(*form4);
		delete form4;

		// Test 3: Invalid form name (should throw exception)
		intern.makeForm("invalid form", "test");

	}catch(const std::exception& e){
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	return 0;
}