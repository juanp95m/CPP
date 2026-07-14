#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include "Contact.hpp"

class PhoneBook {
private:
	Contact	_contacts[8];
	int		_index;
	int		_count;

public:
	PhoneBook(void);
	~PhoneBook(void);

	void addContact(void);
	void printTable(void) const;
	void searchContact(void) const;
};


#endif