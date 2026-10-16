#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default"){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy), _target(copy._target){}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :  AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy) {
	AForm::operator=(copy);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::executeAction() const {
	if (std::rand() % 2 == 0)
	{
		std::cout << "* DRILLING NOISES: BZZZZZZ VRRRRR... *" << std::endl;
		std::cout << this->_target << " has been robotomized successfully!" << std::endl;
	}
	else
		std::cout << "The robotomy on " << this->_target << " failed." << std::endl;
}