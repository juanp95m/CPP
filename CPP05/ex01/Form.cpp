#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() : _name("Default Form"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    std::cout << "Bureaucrat's parameters constructor called" << std::endl;
    if (gradeToExecute < 1 || gradeToSign < 1)
        GradeTooHighException();
    if (gradeToExecute > 150 || gradeToSign > 150)
        GradeTooLowException();
}

Form::Form(const  Form& copy) : _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {}

Form& Form::operator=(const Form& copy) {
    if (this != &copy)
        this->_isSigned = copy._isSigned;
}

