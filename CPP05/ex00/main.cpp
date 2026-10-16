#include "Bureaucrat.hpp"

int main() {
	std::cout << "=== 1. Basic instantiation and assignment ===" << std::endl;
	Bureaucrat human1;
	Bureaucrat human2("Subdirector", 2);
	Bureaucrat human3;

	human3 = human2;

	std::cout << human1 << std::endl;
	std::cout << human2 << std::endl;
	std::cout << human3 << std::endl;

	std::cout << "\n=== 2. Increment and decrement tests ===" << std::endl;

	std::cout << "------------Decreasing-----------" << std::endl;
	try {
		std::cout << "Before: " << human3 << std::endl;
		human3.decrementGrade();
		std::cout << "After: " << human3 << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "------------------------------------" << std::endl;

	try {
		std::cout << "Atempting to decrement: " << human1 << std::endl;
		human1.decrementGrade();
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n------------Incresing-----------" << std::endl;

	try {
		std::cout << "Before: " << human2 << std::endl;
		human2.incrementGrade();
		std::cout << "After: " << human2 << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

		std::cout << "------------------------------------" << std::endl;

	try {
		std::cout << "Atempting to increment: " << human2 << std::endl;
		human2.incrementGrade();
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n=== 3. Instantiation error tests ===" << std::endl;

	try {
		std::cout << "Attempting to instantiate with degree 0:" << std::endl;
		Bureaucrat person1("NEO", 0);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "Attempting to instantiate with degree 1000:" << std::endl;
		Bureaucrat person2("Bob Esponja", 1000);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}