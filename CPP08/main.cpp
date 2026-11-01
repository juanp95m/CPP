#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main()
{
	// Test 1: std::vector (caso de éxito y caso de fallo)
	std::cout << "--- Test con std::vector ---" << std::endl;
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);

	try
	{
		std::vector<int>::iterator it = easyfind(vec, 20);
		std::cout << "Encontrado en vector: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try
	{
		std::vector<int>::iterator it = easyfind(vec, 42);
		std::cout << "Encontrado en vector: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	// Test 2: std::list (caso de éxito)
	std::cout << "\n--- Test con std::list ---" << std::endl;
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(15);
	lst.push_back(25);

	try
	{
		std::list<int>::iterator it = easyfind(lst, 15);
		std::cout << "Encontrado en list: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	// Test 3: Contenedor constante
	std::cout << "\n--- Test con contenedor const ---" << std::endl;
	const std::vector<int> constVec(vec);

	try
	{
		std::vector<int>::const_iterator it = easyfind(constVec, 10);
		std::cout << "Encontrado en const vector: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}