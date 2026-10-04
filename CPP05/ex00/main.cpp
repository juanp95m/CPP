#include "Bureaucrat.hpp"

int main() {
	std::cout << "=== 1. Instanciacion basica y asignacion ===" << std::endl;
	Bureaucrat human1; // Por defecto: "Default", 150
	Bureaucrat human2("Harry Potter", 2);
	Bureaucrat human3;

	human3 = human2; // Solo copia el grado, _name permanece constante

	std::cout << human1 << std::endl;
	std::cout << human2 << std::endl;
	std::cout << human3 << std::endl;

	std::cout << "\n=== 2. Pruebas de incremento y decremento ===" << std::endl;

	std::cout << "------------Decrementando-----------" << std::endl;
	// Decrementar a human3 (pasa de 2 a 3)
	try {
		std::cout << "Antes: " << human3 << std::endl;
		human3.decrementGrade();
		std::cout << "Despues: " << human3 << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "------------------------------------" << std::endl;

	// Decrementar al limite: human1 tiene grado 150, debe lanzar excepcion
	try {
		std::cout << "Intentando decrementar a: " << human1 << std::endl;
		human1.decrementGrade();
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n------------Incrementando-----------" << std::endl;

	// Incrementar a human2: de 2 a 1 (permitido)
	try {
		std::cout << "Antes: " << human2 << std::endl;
		human2.incrementGrade();
		std::cout << "Despues: " << human2 << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

		std::cout << "------------------------------------" << std::endl;

	// Incrementar al limite: human2 tiene grado 1, debe lanzar excepcion
	try {
		std::cout << "Intentando incrementar a: " << human2 << std::endl;
		human2.incrementGrade();
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n=== 3. Pruebas de error en instanciacion ===" << std::endl;

	// Caso: Rango demasiado alto (< 1)
	try {
		std::cout << "Intentando instanciar con grado 0:" << std::endl;
		Bureaucrat person1("NEO", 0);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	// Caso: Rango demasiado bajo (> 150)
	try {
		std::cout << "Intentando instanciar con grado 1000:" << std::endl;
		Bureaucrat person2("Bob Esponja", 1000);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}