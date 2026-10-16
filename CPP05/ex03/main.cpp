#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreatingForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	std::srand(time(NULL));
	Intern someRandomIntern;
	Bureaucrat boss("El Jefe", 47);

	AForm* rrf = NULL;
	AForm* scf = NULL;
	AForm* ppf = NULL;
	AForm* unknown = NULL;

	std::cout << "\n=== 1. Test: Robotomy Request ===" << std::endl;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	if (rrf) {
		boss.signForm(*rrf);
		boss.executeForm(*rrf);
		delete rrf;
	}

	std::cout << "\n=== 2. Test: Shrubbery Creation ===" << std::endl;
	scf = someRandomIntern.makeForm("shrubbery creation", "patio");
	if (scf) {
		boss.signForm(*scf);
		boss.executeForm(*scf);
		delete scf;
	}

	std::cout << "\n=== 3. Test: Presidential Pardon ===" << std::endl;
	ppf = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");
	if (ppf) {
		boss.signForm(*ppf);
		boss.executeForm(*ppf);
		delete ppf;
	}

	std::cout << "\n=== 4. Test: Non-existent form ===" << std::endl;
	unknown = someRandomIntern.makeForm("coffee request", "Espresso");
	if (unknown) {
		delete unknown;
	}

	std::cout << "\n=== The end of tests ===" << std::endl;
	return 0;
}