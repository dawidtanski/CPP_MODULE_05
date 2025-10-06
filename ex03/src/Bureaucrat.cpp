#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"

Bureaucrat::Bureaucrat(int grade):_name("Bureaucrat"),_grade(grade){
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat(){
}

Bureaucrat::Bureaucrat(const Bureaucrat& other):_name(other._name),_grade(other._grade){
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
	if (this != &other){
		_grade = other._grade;
	}
	return *this;
}

const std::string Bureaucrat::getName() const{
	return _name;
}

int Bureaucrat::getGrade() const{
	return _grade;
}

void	Bureaucrat::gradeUp(){
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::gradeDown(){
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b){
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return "Bureaucrat: grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return "Bureaucrat: grade too low";
}

void	Bureaucrat::signForm(AForm& f) const{
	try{
		f.beSigned(*this);
		std::cout << getName() << " signed " << f.getName() << std::endl;
	} catch (const std::exception& e){
		std::cout << getName() << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm &f) const{
	try{
		f.execute(*this);
		std::cout << getName() << " executed " << f.getName() << std::endl;
	} catch (const std::exception& e){
		std::cout << getName() << " couldn't execute " << f.getName() << " because " << e.what() << std::endl;
	}
}