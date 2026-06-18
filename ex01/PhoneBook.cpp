#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void){
	this->_index = 0;
	this->_count = 0;
	return ;
}

PhoneBook::~PhoneBook(void){
	return ;
}

void PhoneBook::addContact(void){
	std::string temp;
	std::cout << "First name: ";
	std::getline(std::cin, temp);
	if (std::cin.eof())
		std::cout << std::endl;
	_contacts[_index].setFirstName(temp);
	std::cout << "Last Name: ";
	std::getline(std::cin, temp);
	if (std::cin.eof())
		std::cout << std::endl;
	_contacts[_index].setLastName(temp);
	std::cout << "Nick name: ";
	std::getline(std::cin, temp);
	if (std::cin.eof())
		std::cout << std::endl;
	_contacts[_index].setNickName(temp);
	std::cout << "Phone number: ";
	std::getline(std::cin, temp);
	if (std::cin.eof())
		std::cout << std::endl;
	_contacts[_index].setPhoneNumber(temp);
	std::cout << "Secret Number: ";
	std::getline(std::cin, temp);
	if (std::cin.eof())
		std::cout << std::endl;
	_contacts[_index].setDarkestSecret(temp);
	_index = (_index + 1) % 8;
	if (_count < 8)
		++_count;
}

void PhoneBook::searchContact(void){
	std::string input;
	for (int i = 0; i < _count; ++i)
	{

	}
}
