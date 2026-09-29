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