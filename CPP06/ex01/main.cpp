#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main() {
	Data originalData;
	originalData.name = "Juan";
	originalData.value = 42;
	originalData.ratio = 3.14159;

	std::cout << "=== DATOS ORIGINALES ===" << std::endl;
	std::cout << "Dirección original: " << &originalData << std::endl;
	std::cout << "Nombre: " << originalData.name << std::endl;
	std::cout << "Valor:  " << originalData.value << std::endl;
	std::cout << "Ratio:  " << originalData.ratio << std::endl;
	std::cout << std::endl;

	// 1. Serialización (puntero -> entero)
	uintptr_t raw = Serializer::serialize(&originalData);
	std::cout << "=== SERIALIZACIÓN ===" << std::endl;
	std::cout << "Valor raw (entero uintptr_t): " << raw << std::endl;
	std::cout << "Valor raw en hexadecimal:    0x" << std::hex << raw << std::dec << std::endl;
	std::cout << std::endl;

	// 2. Deserialización (entero -> puntero)
	Data* deserializedData = Serializer::deserialize(raw);
	std::cout << "=== DESERIALIZACIÓN ===" << std::endl;
	std::cout << "Dirección recuperada: " << deserializedData << std::endl;
	std::cout << "Nombre: " << deserializedData->name << std::endl;
	std::cout << "Valor:  " << deserializedData->value << std::endl;
	std::cout << "Ratio:  " << deserializedData->ratio << std::endl;
	std::cout << std::endl;

	// 3. Comprobación de integridad
	std::cout << "=== RESULTADO DEL TEST ===" << std::endl;
	if (deserializedData == &originalData) {
		std::cout << "OK: El puntero recuperado es idéntico a la dirección original." << std::endl;
	} else {
		std::cout << "ERROR: Las direcciones no coinciden." << std::endl;
	}

	return 0;
}