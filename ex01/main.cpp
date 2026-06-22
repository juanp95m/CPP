#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	book;
	std::string input;

	while (true)
	{
		std::cout << "Write a command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, input)) {
			break ;
		}
		if (input == "ADD") {
			book.addContact();
		}
		else if (input == "SEARCH") {
			book.searchContact();
		}
		else if (input == "EXIT") {
			break ;
		}
		else if (!input.empty()) {
			std::cout << "Please, try again (ADD, SEARCH, EXIT)" << std::endl;
		}
	}
	return (0);
}