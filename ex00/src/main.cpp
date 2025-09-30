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


}