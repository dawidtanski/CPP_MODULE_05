#pragma once
#include <iostream>
#include <fstream>

class Form{

		private:
			const std::string _name;
			bool	_signed;
			const int _gradeToSign;
			const int _gradeToExec;

		public:
			Form();
			~Form();
			Form(const Form& other);
			Form& operator=(const Form& other);
};

std::ostream& operator<<(std::ostream& os, Form& f);