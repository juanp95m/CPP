#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include "Contact.hpp"

class PhoneBook {
private:
	Contact	_contacts[8]; // Array de 8 objetos Contact
	int		_index;       //Nos servirá para saber dónde insertar el siguiente
	int		_count;

public:
	PhoneBook(void);
	~PhoneBook(void);

	void addContact(void);
	void searchContact(void);

};


#endif