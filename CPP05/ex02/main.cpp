#include "Bureaucrat.hpp"
#include "ShrubberyCreatingForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main() {
	std::srand(std::time(NULL));
	Bureaucrat boss("El Jefe", 1);
	Bureaucrat manager("Encargado", 40);
	Bureaucrat intern("Becario", 150);
	std::cout << "\n==============================================" << std::endl;
	std::cout << "  1. TEST: ShrubberyCreatingForm (Sign 145, Exec 137)" << std::endl;
	std::cout << "==============================================" << std::endl;
	{
		ShrubberyCreatingForm shrub("jardin");

		std::cout << "\n[ERRORS]" << std::endl;

		boss.executeForm(shrub);

		Bureaucrat invalid("Becario", 146);
		invalid.signForm(shrub);

		std::cout << "\n[SUCCESS]" << std::endl;
		intern.signForm(shrub);
		manager.signForm(shrub);
		manager.executeForm(shrub);
	}

	std::cout << "\n==============================================" << std::endl;
	std::cout << "  2. TEST: RobotomyRequestForm (Sign 72, Exec 45)" << std::endl;
	std::cout << "==============================================" << std::endl;
	{
		RobotomyRequestForm robot("Bender");

		std::cout << "\n[ERRORS]" << std::endl;

		manager.executeForm(robot);


		intern.signForm(robot);

		std::cout << "\n[SUCCESS]" << std::endl;
		manager.signForm(robot);
		intern.executeForm(robot);
		manager.executeForm(robot);
		boss.executeForm(robot);
	}

	std::cout << "\n==============================================" << std::endl;
	std::cout << "  3. TEST: PresidentialPardonForm (Sign 25, Exec 5)" << std::endl;
	std::cout << "==============================================" << std::endl;
	{
		PresidentialPardonForm pardon("Arthur Dent");

		std::cout << "\n[ERRORS]" << std::endl;

		boss.executeForm(pardon);

		manager.signForm(pardon);

		std::cout << "\n[SUCCESS]" << std::endl;
		boss.signForm(pardon);
		manager.executeForm(pardon);
		boss.executeForm(pardon);
	}

	std::cout << "\n==============================================" << std::endl;
	std::cout << "  END OF TESTING" << std::endl;
	std::cout << "==============================================" << std::endl;

	return 0;
}