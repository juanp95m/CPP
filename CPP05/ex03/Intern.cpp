#include "Intern.hpp"
#include "ShrubberyCreatingForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern& copy) {
	*this = copy;
}

Intern& Intern::operator=(const Intern& copy) {
	(void)copy;
	return *this;
}

Intern::~Intern() {}

static AForm* createShrubbery(const std::string& target) {
	return new ShrubberyCreatingForm(target);
}

static AForm* createRobotomy(const std::string& target) {
	return new RobotomyRequestForm(target);
}

static AForm* createPresidential(const std::string& target) {
	return new PresidentialPardonForm(target);
}


AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
	std::string formNames[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* (*creators[])(const std::string&) = {
		&createShrubbery,
		&createRobotomy,
		&createPresidential
	};

	for (int i = 0; i < 3; i++) {
		if (formName == formNames[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			std::cout << "---" << *creators[i](target) << "---"  << std::endl;
			return creators[i](target);
		}
	}

	std::cout << "Intern couldn't create form because \"" << formName << "\" does not exist." << std::endl;
	return NULL;
}

