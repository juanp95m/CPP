#include <iostream>
#include <string>
#include "Array.hpp"

int main(void) {
	std::cout << "--- 1. Array vacío ---" << std::endl;
	Array<int> emptyArr;
	std::cout << "Tamaño array vacío: " << emptyArr.size() << std::endl << std::endl;

	std::cout << "--- 2. Array con tamaño e inicialización por defecto ---" << std::endl;
	Array<int> intArr(5);
	std::cout << "Tamaño: " << intArr.size() << std::endl;
	std::cout << "Valores por defecto (debe ser 0): ";
	for (unsigned int i = 0; i < intArr.size(); ++i)
		std::cout << intArr[i] << " ";
	std::cout << std::endl;

	// Asignamos valores
	for (unsigned int i = 0; i < intArr.size(); ++i)
		intArr[i] = (i + 1) * 10;

	std::cout << "Valores modificados: ";
	for (unsigned int i = 0; i < intArr.size(); ++i)
		std::cout << intArr[i] << " ";
	std::cout << std::endl << std::endl;

	std::cout << "--- 3. Prueba de copia profunda (Deep Copy) ---" << std::endl;
	Array<int> copyArr = intArr;
	copyArr[0] = 999; // Modificamos solo la copia

	std::cout << "Original intArr[0]: " << intArr[0] << " (debe seguir siendo 10)" << std::endl;
	std::cout << "Copia copyArr[0]:   " << copyArr[0] << " (debe ser 999)" << std::endl << std::endl;

	std::cout << "--- 4. Array de cadenas (std::string) y const ---" << std::endl;
	Array<std::string> strArr(3);
	strArr[0] = "42";
	strArr[1] = "Málaga";
	strArr[2] = "Templates";

	const Array<std::string> constStrArr = strArr;
	std::cout << "Lectura desde const Array: ";
	for (unsigned int i = 0; i < constStrArr.size(); ++i)
		std::cout << constStrArr[i] << " ";
	std::cout << std::endl << std::endl;

	std::cout << "--- 5. Prueba de gestión de excepciones fuera de límites ---" << std::endl;
	try {
		std::cout << "Intentando acceder al índice 5 en un array de tamaño 5..." << std::endl;
		std::cout << intArr[5] << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Excepción capturada con éxito: " << e.what() << std::endl;
	}

	try {
		std::cout << "Intentando acceder a un índice de array vacío..." << std::endl;
		std::cout << emptyArr[0] << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Excepción capturada con éxito: " << e.what() << std::endl;
	}

	return 0;
}