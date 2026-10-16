#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	
	std::cout << "\n=== 1. Valid creation and operator << ===" << std::endl;
	Bureaucrat boss("The Boss", 10);
	Bureaucrat intern("scholar", 140);
	Form contract("rental agreement", 50, 25);
	
	std::cout << boss << std::endl;
	std::cout << intern << std::endl;
	std::cout << contract << std::endl;
	
	std::cout << "\n=== 2. Failed signing attempt (insufficient rank) ===" << std::endl;
	
	intern.signForm(contract);
	std::cout << "Status after attempt: " << (contract.getIsSigned() ? "Signed" : "Unsigned") << std::endl;
	
	std::cout << "\n=== 3. Successful signing attempt ===" << std::endl;
	
	boss.signForm(contract);
	std::cout << "Status after sign: " << (contract.getIsSigned() ? "Signed" : "Unsigned") << std::endl;
	
	std::cout << "\n=== 4. Final information verification with << ===" << std::endl;
	std::cout << contract << std::endl;
	
	std::cout << "=== 5. Error validation when instantiating Form ===" << std::endl;
	std::cout << "Degree of over-signing too high (< 1) " << std::endl;
	try {
		Form invalidForm1("Top Secret", 0, 50);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "Execution grade too low (> 150) " << std::endl;
	
	try {
		Form invalidForm2("Tax Form", 50, 151);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	std::cout << "=== DESTRUCTION ===" << std::endl;
	return 0;
}