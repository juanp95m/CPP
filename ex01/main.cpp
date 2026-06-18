#include "PhoneBook.hpp"

// int main(void)
// {
// 	PhoneBook PhoneBook;
// 	std::string input;

// 	while (true)
// 	{
// 		std::cout << "Write a command (ADD, SEARCH, EXIT):" << std::endl;
// 		if (!std::getline(std::cin, command)) {
//            break ;
//        }
// 		if (input == "ADD")
// 			PhoneBook.addContact();
// 		else if (input == "SEARCH")
//			PhoneBook.searchContact();
//		else if (input == "EXIT")
//			break ;
//		else
//			std::cout << "Please, try again (ADD, SEARCH, EXIT)" << std::endl;
// 	}
//	return (0);
// }

int main()
{
	PhoneBook PhoneBook;
	Contact Contact;
	std::string input;
	std::cout << "add name" << std:: endl;
	if (getline(std::cin, input)) 
		Contact.getFirstName();
	else
		std::cout << "Error crack" << std:: endl;
	Contact.getFirstName();
}