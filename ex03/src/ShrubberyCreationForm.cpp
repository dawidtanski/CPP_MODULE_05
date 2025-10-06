#include "../inc/ShrubberyCreationForm.hpp"
#include <fstream>


ShrubberyCreationForm::ShrubberyCreationForm():AForm("ShrubberyCreationForm", 145, 137),_target("target"){
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target):AForm("ShrubberyCreationForm", 145, 137),_target(target){
}

ShrubberyCreationForm::~ShrubberyCreationForm(){};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other):AForm(other), _target(other._target){
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other){
	if (this != &other){
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}



void ShrubberyCreationForm::doExec() const{

	std::string fileName = _target + "_shrubbery";
	const char* fileName_cStr = fileName.c_str();
	std::ofstream file(fileName_cStr);

	if (file.is_open()){
		file << 
		"       oxoxoo    ooxoo\n"
        "    ooxoxo oo  oxoxooo\n"
        "   oooo xxoxoo ooo ooox\n"
        "   oxo o oxoxo  xoxxoxo\n"
        "   oxo xooxoooo o ooo\n"
        "       ooo\\oo\\  /o/o\n"
        "           \\  \\/ /\n"
        "            |   /\n"
        "            |  |\n"
        "            | D|\n"
        "            |  |\n"
        "            |  |\n"
		<< std::endl;
		file.close();
	}
	else{
		std::cerr << "Cannot open the file" << std::endl;
	}
}