#include "../inc/Bureaucrat.hpp"

int main(){

	try{
		Bureaucrat bur(70);
		// Bureaucrat bur2(170);
		Bureaucrat bur3(-3);
		std::cout << bur;
		bur.gradeDown();
		std::cout << bur;
		bur.gradeUp();
		std::cout << bur;
	}catch(const std::exception& e){
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	// Additional tests
	try{
		// Test 1: Bureaucrat with maximum grade
		Bureaucrat bur_max(1);
		std::cout << "Max grade: " << bur_max << std::endl;

		// Test 2: Try gradeUp on maximum grade (should throw exception)
		bur_max.gradeUp();

	}catch(const std::exception& e){
		std::cerr << "Additional test exception: " << e.what() << std::endl;
	}

	return 0;
}