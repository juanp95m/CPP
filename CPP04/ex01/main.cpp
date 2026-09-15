#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	std::cout << "=== 1. CREANDO ARRAY DE ANIMALES ===" << std::endl;
	const Animal* animals[10];

	std::cout << "\n-- Creando 5 Dogs --" << std::endl;
	for (int i = 0; i < 5; ++i)
		animals[i] = new Dog();

	std::cout << "\n-- Creando 5 Cats --" << std::endl;
	for (int i = 5; i < 10; ++i)
		animals[i] = new Cat();

	std::cout << "\n=== 2. PRUEBA DE COPIA PROFUNDA (DEEP COPY) ===" << std::endl;
	{
		std::cout << "Creando originalDog..." << std::endl;
		Dog originalDog;

		std::cout << "\nEntrando en ambito temporal para copiar..." << std::endl;
		{
			Dog copyDog = originalDog; // Constructor de copia
			std::cout << "Saliendo del ambito temporal (destruyendo copyDog)..." << std::endl;
		} // copyDog se destruye aqui. Si la copia fuera superficial, destruiria el cerebro de originalDog

		std::cout << "\noriginalDog sigue vivo de forma independiente." << std::endl;
		std::cout << "Destruyendo originalDog..." << std::endl;
	}

	std::cout << "\n=== 3. DESTRUYENDO ARRAY DE ANIMALES ===" << std::endl;
	for (int i = 0; i < 10; ++i)
	{
		std::cout << "\nBorrando animal en posicion [" << i << "]:" << std::endl;
		delete animals[i];
	}

	std::cout << "\n=== FIN DEL PROGRAMA ===" << std::endl;
	return 0;
}