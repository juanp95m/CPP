#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main()
{
	std::cout << "--- Test con MutantStack ---" << std::endl;
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << "Top:  " << mstack.top() << std::endl;

		mstack.pop();

		std::cout << "Size: " << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		// [...]
		mstack.push(0);

		MutantStack<int>::iterator itstart = mstack.begin();
		MutantStack<int>::iterator itend = mstack.end();

		++itstart;
		--itstart;

		std::cout << "Elementos iterados:" << std::endl;
		while (itstart != itend)
		{
			std::cout << *itstart << std::endl;
			++itstart;
		}
		std::stack<int> s(mstack);
	}

	std::cout << "\n--- Test equivalente con std::list ---" << std::endl;
	{
		std::list<int> mlist;

		mlist.push_back(5);
		mlist.push_back(17);

		std::cout << "Top:  " << mlist.back() << std::endl;

		mlist.pop_back();

		std::cout << "Size: " << mlist.size() << std::endl;

		mlist.push_back(3);
		mlist.push_back(5);
		mlist.push_back(737);
		// [...]
		mlist.push_back(0);

		std::list<int>::iterator itstart = mlist.begin();
		std::list<int>::iterator itend = mlist.end();

		++itstart;
		--itstart;

		std::cout << "Elementos iterados:" << std::endl;
		while (itstart != itend)
		{
			std::cout << *itstart << std::endl;
			++itstart;
		}
	}

	std::cout << "\n--- Test con const_iterator ---" << std::endl;
{
	MutantStack<int> mstack;
	mstack.push(10);
	mstack.push(20);
	mstack.push(30);

	// Creamos una referencia constante a la pila
	const MutantStack<int> &const_stack = mstack;

	// Aquí el compilador obliga a usar const_iterator
	MutantStack<int>::const_iterator citstart = const_stack.begin();
	MutantStack<int>::const_iterator citend = const_stack.end();

	std::cout << "Lectura constante:" << std::endl;
	while (citstart != citend)
	{
		std::cout << *citstart << std::endl; // Lectura permitida
		// *cit = 42; // <-- Si descomentas esta línea, el compilador debe dar error
		++citstart;
	}
}

	return 0;
}