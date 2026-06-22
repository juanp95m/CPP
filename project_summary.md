# Resumen del Proyecto: ex01
Generado el: 2026-06-22 17:50:21

## Estructura de Archivos Incluidos
```
  - ex01/PhoneBook.cpp
  - ex01/Contact.cpp
  - ex01/main.cpp
```

## Contenido de los Archivos

### Archivo: `ex01/PhoneBook.cpp`
```cpp
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
std::string formatColumn(std::string text) {
    if (text.length() > 10) {
        return text.substr(0, 9) + ".";
    }
    return text;
}

void PhoneBook::printTable(void) const
{
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
	this->printTable();
	std::cout << "Enter contact index to display";
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
		std::cout << this->_contacts[num].getFirstName() << std::endl;
		std::cout << this->_contacts[num].getLastName() << std::endl;
		std::cout << this->_contacts[num].getNickName() << std::endl;
		std::cout << this->_contacts[num].getPhoneNumber() << std::endl;
		std::cout << this->_contacts[num].getDarkestSecret() << std::endl;
	}
}


// FUNCION PhoneBook::searchContact()
    
//     PASO 1: Mostrar la tabla con los contactos
//     Llamar a la función que ya tenemos hecha (printTable)
    
//     PASO 2: Solicitar el índice al usuario
//     Imprimir en pantalla "Introduce el índice del contacto a mostrar: "
//     Leer la línea completa que introduzca el usuario usando 'std::getline' y guardarla en un std::string (llamémoslo 'input')
    
//     PASO 3: Validar la entrada (Control de errores)
//     SI el 'input' está vacío O su longitud es diferente de 1:
//         Imprimir "Error: Índice inválido."
//         TERMINAR FUNCIÓN
        
//     PASO 4: Convertir el carácter a número entero
//     Como 'input' tiene longitud 1, el carácter del índice es 'input[0]'
//     Convertir ese carácter a un número entero (restando '0' como hacías en C) y guardarlo en una variable 'int index'
    
//     PASO 5: Comprobar si el número está dentro del rango válido
//     SI 'index' es menor que 0 O 'index' es mayor o igual que '_count':
//         Imprimir "Error: Número fuera de rango."
//     SINO:
//         // El índice es totalmente seguro y válido
//         PASO 6: Mostrar la información completa del contacto
//         Imprimir el First Name completo usando tu getter
//         Imprimir el Last Name completo usando tu getter
//         ... (repetir para los 5 campos de ese contacto concreto, uno por línea)
        
// FIN FUNCIÓN

```

### Archivo: `ex01/Contact.cpp`
```cpp
#include "Contact.hpp"

Contact::Contact(void){
	return ;
}

Contact::~Contact(void){
	return ;
}

std::string Contact:: getFirstName(void) const {
	return (this->_firstName);
}

std::string Contact:: getLastName(void) const {
	return (this->_lastName);
}

std:: string Contact:: getNickName(void) const {
	return (this->_nickname);
}

std:: string Contact:: getPhoneNumber(void) const {
	return (this->_phoneNumber);
}

std:: string Contact:: getDarkestSecret(void) const {
	return (this->_darkestSecret);
}

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
```

### Archivo: `ex01/main.cpp`
```cpp
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
```

