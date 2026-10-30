#include "iter.hpp"

template <typename T>
void plusOne(T &val) {
	val += 1;
}

template <typename T>
void printElement(const T &val) {
	std::cout << val << " ";
}

int main(void) {
	std::cout << "--- 1. Array de enteros modificable ---" << std::endl;
	int numbers[] = {1, 2, 3, 4, 5};
	const std::size_t numLen = 5;

	std::cout << "Original: ";
	::iter(numbers, numLen, printElement<int>);
	std::cout << std::endl;

	::iter(numbers, numLen, plusOne<int>);

	std::cout << "Incrementado (+1): ";
	::iter(numbers, numLen, printElement<int>);
	std::cout << std::endl << std::endl;

	std::cout << "--- 2. Array constante de cadenas (solo lectura) ---" << std::endl;
	const std::string words[] = {"42", "Malaga", "Templates", "C++98"};
	const std::size_t strLen = 4;

	std::cout << "Palabras: ";

	::iter(words, strLen, printElement<std::string>);
	std::cout << std::endl;

	return 0;
}