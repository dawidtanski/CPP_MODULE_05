#include "../inc/Bureaucrat.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main(){
	srand(time(NULL));

	try{
		Bureaucrat bur("Alice", 5);
		// Bureaucrat bur2("Bob", 1);
		RobotomyRequestForm form1("Marvin");
		ShrubberyCreationForm form2("garden");
		PresidentialPardonForm form3("Ford Prefect");

		bur.signForm(form1);
		bur.signForm(form2);
		bur.signForm(form3);
		std::cout << "------------------------------------" << std::endl;
		bur.executeForm(form1);
		std::cout << "------------------------------------" << std::endl;
		bur.executeForm(form2);
		std::cout << "------------------------------------" << std::endl;
		bur.executeForm(form3);
		// bur2.signForm(form1);

		// Bureaucrat bur2(170);
		// Bureaucrat bur3(-3);
		// std::cout << bur;
		// bur.gradeDown();
		// std::cout << bur;
		// bur.gradeUp();
		// std::cout << bur;
	}catch(const std::exception& e){
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	// Additional tests
	try{
		Bureaucrat bur_high("Boss", 1);  // High grade
		Bureaucrat bur_low("Intern", 150);  // Low grade
		RobotomyRequestForm form4("Bender");
		ShrubberyCreationForm form5("home");

		// Test 1: Execute without signing
		bur_high.executeForm(form4);

		// Test 2: Sign with low grade bureaucrat
		bur_low.signForm(form5);

	}catch(const std::exception& e){
		std::cerr << "Additional test exception: " << e.what() << std::endl;
	}

	return 0;
}