#include "../inc/Bureaucrat.hpp"

int main(){

	try{
		Bureaucrat bur("John", 70);
		Bureaucrat bur2("Boss", 1);
		Form form1("Tax Form", 50, 25);

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
		Bureaucrat bur_high("CEO", 1);
		Form form2("Important Document", 5, 1);

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