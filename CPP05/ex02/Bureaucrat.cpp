#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
	std::cout << "Bureaucrat's constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name) , _grade(copy._grade) {
	std::cout << "Bureaucrat's copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& copy) {
	if (this != &copy)
		this->_grade = copy._grade;
	return *this;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {

	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "Bureaucrat's parameters constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat's destructor called " << _name << std::endl;
}

std::string Bureaucrat::getName() const {
	return this->_name;
}

int Bureaucrat::getGrade() const {
	return this->_grade;
}

void Bureaucrat::incrementGrade() {
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade -= 1;
}

void Bureaucrat::decrementGrade() {
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade += 1;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return out;
}

void Bureaucrat::signForm(Form& form) {
	try {
		form.beSigned(*this);
	}
		catch (const std::exception& e) {
			std::cout << this->getName() << " couldn't sign "
			<< form.getName() << " because " << e.what() << std::endl;
			return ;
		}
	std::cout << this->getName() << " signed " << form.getName() << std::endl;
}