#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() : _name("Default Form"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	std::cout << "Form's parameters constructor called to create: " << _name << std::endl;
	if (gradeToExecute < 1 || gradeToSign < 1)
		throw Form::GradeTooHighException();
	if (gradeToExecute > 150 || gradeToSign > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const  Form& copy) : _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {}

Form& Form::operator=(const Form& copy) {
	if (this != &copy)
		this->_isSigned = copy._isSigned;
	return *this;
}

Form::~Form(){
	std::cout << "Form's destructor called" << std::endl;
}

const std::string& Form::getName() const {
	return _name;
}

bool Form::getIsSigned() const {
	return _isSigned;
}

int Form::getGradeToSigned() const {
	return _gradeToSign;
}

int Form::getGradeToExecute() const {
	return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	this->_isSigned = true;
}

std::ostream& operator<<(std::ostream& out, const Form& form) {

	out << "Form: " << form.getName() << std::endl;
	out << "Signed: " << form.getIsSigned() << std::endl;
	out << "Grade required to sign: " << form.getGradeToSigned() << std::endl;
	out << "Grade required to execute: " << form.getGradeToExecute() << std::endl;

return out;

}

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade too high.";
}



const char* Form::GradeTooLowException::what() const throw() {
	return "Grade too low.";
} 
