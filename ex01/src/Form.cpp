#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"

const char* Form::GradeTooHighException::what() const throw(){
	return "Form: grade too high";
}

const char* Form::GradeTooLowException::what() const throw(){
	return "Form: grade too low";
}

Form::Form():_name("Form"), _signed(false), _gradeToSign(15), _gradeToExec(5){
}

Form::~Form(){}

Form::Form(const Form& other):_name(other._name),_signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec){

}

Form& Form::operator=(const Form& other){
	if (this != &other){
		_signed = other._signed;
	}
	return *this;
}

void	Form::beSigned(const Bureaucrat& bur){
	if (bur.getGrade() <= _gradeToSign)
		_signed = true;
	else
		throw GradeTooLowException();
}

bool Form::getSigned() const{
	return _signed;
}

const std::string Form::getName() const{
	return _name;
}

int Form::getGradeToSign() const{
	return _gradeToSign;
}

int Form::getGradeToExec() const{
	return _gradeToExec;
}

std::ostream& operator<<(std::ostream& os, const Form& f){
	os << "Form " << f.getName()
		<< " [sign grade: " << f.getGradeToSign()
		<< ", exec grade: " << f.getGradeToExec()
		<< "] is " << (f.getSigned() ? "signed" : "not signed");
    return os;
}