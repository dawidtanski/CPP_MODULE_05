#include "../inc/Bureaucrat.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

int main(){

	try{
		Bureaucrat bur(5);
		// Bureaucrat bur2(1);
		RobotomyRequestForm form1;
		ShrubberyCreationForm form2;
		PresidentialPardonForm form3;

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


}