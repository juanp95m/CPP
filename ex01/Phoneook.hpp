#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class Phonebook {
private:
	Contact	_contacts[8]; // Array de 8 objetos Contact
	int		_index;       //Nos servirá para saber dónde insertar el siguiente

public:
	Phonebook(void);
	~Phonebook(void);

	void add(void);
	void search(void);

};

	void Contact::setFirstName(std::string firstName){
		this->_firstName = firstName;
	}

	void Contact::setLastName(std::string lastName){
		this->_lastName = lastName;
	}

	void Contact::setNickName(std::string nickName){
		this->_nickname = nickName;
	}

	void Contact::setPhoneNumber(std::string phoneNumber){
		this->_phoneNumber = phoneNumber;
	}

	void Contact::setDarkestSecret(std::string darkestSecret){
		this->_darkestSecret = darkestSecret;
	}

#endif