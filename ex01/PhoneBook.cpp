#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void){
	this->_index = 0;
	this->_count = 0;
}

PhoneBook::~PhoneBook(void){
}

static std::string getInput(const std::string& prompt, bool onlyDigits = false) {
	std::string input;

	while (input.empty()) {
		std::cout << prompt;
		std::getline(std::cin, input);

		if (std::cin.eof()) {
			std::cout << std::endl;
			return ""; 
		}

		for (size_t i = 0; i < input.length(); i++) {
			if (input[i] < 32 || input[i] > 127) {
				input.clear();
				std::cout << "Please, only ascii characters" << std::endl;
				break;
			}
			else if (onlyDigits && (input[i] < '0' || input[i] > '9')) {
				input.clear();
				std::cout << "Please, only numbers" << std::endl;
				break;
			}
		}
	}
	return input;
}

void PhoneBook::addContact(void){
	std::string temp;

	temp = getInput("First name: ");
	if (temp.empty())
		return ;
	_contacts[_index].setFirstName(temp);

		temp = getInput("Last name: ");
	if (temp.empty())
		return ;
	_contacts[_index].setLastName(temp);

	temp = getInput("Nick name: ");
	if (temp.empty())
		return ;
	_contacts[_index].setNickName(temp);

	temp = getInput("Phone number: ", true);
	if (temp.empty())
		return ;
	_contacts[_index].setPhoneNumber(temp);

	temp = getInput("Darkest secret: ");
	if (temp.empty())
		return ;
	_contacts[_index].setDarkestSecret(temp);
	_index = (_index + 1) % 8;
	if (_count < 8)
 		++_count;
}

std::string formatColumn(std::string text) {
	if (text.length() > 10) {
		return text.substr(0, 9) + ".";
	}
	return text;
}

void PhoneBook::printTable(void) const
{
	std::cout << "|" << std::setw(10) << "index" << "|" 
			  << std::setw(10) << "First name" << "|" 
			  << std::setw(10) << "Last name" << "|" 
			  << std::setw(10) << "Nickname" << "|" << std::endl;
	for (int i = 0; i < _count; ++i)
	{
		std::cout << "|" << std::setw(10) << i << "|"
				  << std::setw(10) << formatColumn(this->_contacts[i].getFirstName()) << "|"
				  << std::setw(10) << formatColumn(this->_contacts[i].getLastName()) << "|"
				  << std::setw(10) << formatColumn(this->_contacts[i].getNickName()) << "|" << std::endl;
	}
}

void PhoneBook::searchContact(void) const{
	std::string input;
	if (_count == 0){
		std::cout << "Empty Phonebook, please add contact before" << std::endl;
	}
	else{
		this->printTable();
		std::cout << "Enter contact index to display: ";
		if (!std::getline(std::cin, input))
			return ;
		if (input.length() != 1){
			std::cout << "Error: invalid index" << std::endl;
			return ;
		}
		int num = input[0] - '0';
		if (num < 0 || num >=_count)
			std::cout << "Error: Out of range, try again" << std::endl;
		else{
			std::cout << "First Name: " << this->_contacts[num].getFirstName() << std::endl;
			std::cout << "Last name: " << this->_contacts[num].getLastName() << std::endl;
			std::cout << "Nick name: " << this->_contacts[num].getNickName() << std::endl;
			std::cout << "Phone number: " << this->_contacts[num].getPhoneNumber() << std::endl;
			std::cout << "Darkest secret: " << this->_contacts[num].getDarkestSecret() << std::endl;
		}
	}
}



