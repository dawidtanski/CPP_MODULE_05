#include "../inc/Bureaucrat.hpp"

int main(){

	try{
		Bureaucrat bur(70);
		Bureaucrat bur2(1);
		Form form1;

		bur.signForm(form1);
		bur2.signForm(form1);

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
		Bureaucrat bur_high(1);
		Form form2;

		// Test 1: Output Form
		std::cout << form2 << std::endl;

		// Test 2: Sign form again (already signed)
		bur_high.signForm(form2);
		bur_high.signForm(form2);  // Already signed

	}catch(const std::exception& e){
		std::cerr << "Additional test exception: " << e.what() << std::endl;
	}

	return 0;
}