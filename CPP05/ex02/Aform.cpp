
#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default AForm"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	std::cout << "AForm's parameters constructor called" << std::endl;
	if (gradeToExecute < 1 || gradeToSign < 1)
		throw AForm::GradeTooHighException();
	if (gradeToExecute > 150 || gradeToSign > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const  AForm& copy) : _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {}

AForm& AForm::operator=(const AForm& copy) {
	if (this != &copy)
		this->_isSigned = copy._isSigned;
	return *this;
}

AForm::~AForm(){
	std::cout << "AForm's destructor called" << std::endl;
}

const std::string& AForm::getName() const {
	return _name;
}

bool AForm::getIsSigned() const {
	return _isSigned;
}

int AForm::getGradeToSigned() const {
	return _gradeToSign;
}

int AForm::getGradeToExecute() const {
	return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	this->_isSigned = true;
}

std::ostream& operator<<(std::ostream& out, const AForm& Aform) {

	out << "AForm: " << Aform.getName() << std::endl;
	out << "Signed: " << Aform.getIsSigned() << std::endl;
	out << "Grade required to sign: " << Aform.getGradeToSigned() << std::endl;
	out << "Grade required to execute: " << Aform.getGradeToExecute() << std::endl;

	return out;

}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade too high.";
}



const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade too low.";
} 

void AForm::execute(Bureaucrat const & executor) const {
    if (!this->getIsSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    this->executeAction(); // Llama dinámicamente a la acción de la hija
}