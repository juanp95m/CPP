# Resumen del Proyecto: ex01
Generado el: 2026-09-29 12:22:11

## Estructura de Archivos Incluidos
```
  - ex01/Form.cpp
  - ex01/Bureaucrat.cpp
  - ex01/main.cpp
```

## Contenido de los Archivos

### Archivo: `ex01/Form.cpp`
```cpp
#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() : _name("Default Form"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	std::cout << "Bureaucrat's parameters constructor called" << std::endl;
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

void Form::beSigned(const Bureaucrat& form) {
	if (form.getGrade() > this->_gradeToSign)
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
```

### Archivo: `ex01/Bureaucrat.cpp`
```cpp
#include "Bureaucrat.hpp"

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
```

### Archivo: `ex01/main.cpp`
```cpp
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	std::cout << "=== 1. Validacion de errores al instanciar Form ===" << std::endl;
	// Grado para firmar demasiado alto (< 1)
	try {
		Form invalidForm1("Top Secret", 0, 50);
	} catch (std::exception& e) {
		std::cout << "Excepcion capturada: " << e.what() << std::endl;
	}

	// Grado para ejecutar demasiado bajo (> 150)
	try {
		Form invalidForm2("Tax Form", 50, 151);
	} catch (std::exception& e) {
		std::cout << "Excepcion capturada: " << e.what() << std::endl;
	}

	std::cout << "\n=== 2. Creacion valida y operador << ===" << std::endl;
	Bureaucrat boss("El Jefe", 10);
	Bureaucrat intern("Becario", 140);
	Form contract("Contrato de Alquiler", 50, 25);

	std::cout << boss << std::endl;
	std::cout << intern << std::endl;
	std::cout << contract << std::endl;

	std::cout << "\n=== 3. Intento de firma fallido (rango insuficiente) ===" << std::endl;
	// Becario tiene grado 140, pero el contrato exige grado 50 para firmar
	intern.signForm(contract);
	std::cout << "Estado tras intento: " << (contract.getIsSigned() ? "Firmado" : "No firmado") << std::endl;

	std::cout << "\n=== 4. Intento de firma exitoso ===" << std::endl;
	// El Jefe tiene grado 10, suficiente para firmar (exige <= 50)
	boss.signForm(contract);
	std::cout << "Estado tras firma: " << (contract.getIsSigned() ? "Firmado" : "No firmado") << std::endl;

	std::cout << "\n=== 5. Comprobacion de informacion final con << ===" << std::endl;
	std::cout << contract << std::endl;

	return 0;
}
```

