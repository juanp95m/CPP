#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
	Intern someRandomIntern;
	Bureaucrat boss("El Jefe", 1);

	AForm* rrf = NULL;
	AForm* scf = NULL;
	AForm* ppf = NULL;
	AForm* unknown = NULL;

	std::cout << "\n=== 1. Prueba: Robotomy Request ===" << std::endl;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	if (rrf) {
		boss.signForm(*rrf);
		boss.executeForm(*rrf);
		delete rrf;
	}

	std::cout << "\n=== 2. Prueba: Shrubbery Creation ===" << std::endl;
	scf = someRandomIntern.makeForm("shrubbery creation", "patio");
	if (scf) {
		boss.signForm(*scf);
		boss.executeForm(*scf);
		delete scf;
	}

	std::cout << "\n=== 3. Prueba: Presidential Pardon ===" << std::endl;
	ppf = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");
	if (ppf) {
		boss.signForm(*ppf);
		boss.executeForm(*ppf);
		delete ppf;
	}

	std::cout << "\n=== 4. Prueba: Formulario Inexistente ===" << std::endl;
	unknown = someRandomIntern.makeForm("coffee request", "Espresso");
	if (unknown) {
		delete unknown;
	}

	std::cout << "\n=== Fin de pruebas ===" << std::endl;
	return 0;
}