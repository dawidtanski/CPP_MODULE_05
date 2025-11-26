#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"

const char* AForm::GradeTooHighException::what() const throw(){
	return "AForm: grade too high";
}

const char* AForm::GradeTooLowException::what() const throw(){
	return "AForm: grade too low";
}

const char* AForm::FormNotSignedException::what() const throw(){
	return "The form is not signed. You have to sign it before execute!";
}

AForm::AForm():_name("AForm"), _signed(false), _gradeToSign(15), _gradeToExec(5){
}

AForm::AForm(const std::string name, int gradeToSign, int gradeToExec):_name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec){
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
}

AForm::~AForm(){}

AForm::AForm(const AForm& other):_name(other._name),_signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec){

}

AForm& AForm::operator=(const AForm& other){
	if (this != &other){
		_signed = other._signed;
	}
	return *this;
}

void	AForm::beSigned(const Bureaucrat& bur){
	if (bur.getGrade() <= _gradeToSign)
		_signed = true;
	else
		throw GradeTooLowException();
}

bool AForm::getSigned() const{
	return _signed;
}

const std::string AForm::getName() const{
	return _name;
}

int AForm::getGradeToSign() const{
	return _gradeToSign;
}

int AForm::getGradeToExec() const{
	return _gradeToExec;
}

void	AForm::execute(Bureaucrat const &executor) const{
	if (!getSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeToExec())
		throw GradeTooLowException();
	doExec();
}

std::ostream& operator<<(std::ostream& os, const AForm& f){
	os << "Form " << f.getName()
		<< " [sign grade: " << f.getGradeToSign()
		<< ", exec grade: " << f.getGradeToExec()
		<< "] is " << (f.getSigned() ? "signed" : "not signed");
    return os;
}