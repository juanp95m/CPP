#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include "Contact.hpp"

// PhoneBook será la clase "controladora", que contendrá un array fijo de 
// 8 instancias de la clase Contact y las funciones principales de la agenda (ADD, SEARCH, EXIT)
class PhoneBook {
private:
	Contact	_contacts[8]; // Array de 8 objetos Contact
	int		_index;       //Nos servirá para saber dónde insertar el siguiente
	int		_count;       // te dice CUÁNTOS contactos reales existen para poder mostrarlos.

public:
	PhoneBook(void);  // El constructor inicializa las variables internas al nacer el objetos (como poner tus contadores a 0)
	~PhoneBook(void); 

	// Métodos principales que llamará el main
	void addContact(void);
	void searchContact(void);

};


#endif