# Resumen del Proyecto: CPP00
Generado el: 2026-06-16 17:35:52

## Estructura de Archivos Incluidos
```
  - ./ex00/Makefile
  - ./ex00/megaphone.cpp
  - ./ex01/Makefile
  - ./ex01/PhoneBook.cpp
  - ./ex01/Contact.hpp
  - ./ex01/Phoneook.hpp
  - ./ex01/Contact.cpp
```

## Contenido de los Archivos

### Archivo: `./ex00/Makefile`
```
# Name of executable
NAME = megaphone

# Compilation flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Sources
SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)

# Main rule
all: $(NAME)

# Executablee compilation
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
```

### Archivo: `./ex00/megaphone.cpp`
```cpp
#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		for(int i = 1; i < argc; i++)
		{
			for(int j = 0; argv[i][j]; j++)
				std::cout << (char) std::toupper(argv[i][j]);
		}
		std::cout << std::endl;
	}
	return (0);
}
```

### Archivo: `./ex01/Makefile`
```
# Name of executable
NAME = megaphone

# Compilation flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Sources
SRCS = Phonebook.cpp Phonebook.cpp
	Contact.
OBJS = $(SRCS:.cpp=.o)

# Main rule
all: $(NAME)

# Executablee compilation
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
```

### Archivo: `./ex01/PhoneBook.cpp`
```cpp
#include "Phonebook.hpp"

#include <iostream>


```

### Archivo: `./ex01/Contact.hpp`
```hpp
#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact {
private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _darkestSecret;
public:
	Contact(void);
	~Contact(void);
	
	std::string getFirstName(void) const;
	std::string getLastName(void) const;
	std::string getNickName(void) const;
	std::string getPhoneNumber(void) const;
	std::string getDarkestSecret(void) const;
	void	setFirstName(std::string firstName);
	void	setLastName(std::string lastName);
	void	setNickName(std::string nickName);
	void	setPhoneNumber(std::string phoneNumber);
	void	setDarkestSecret(std::string darkestSecret);
};
#endif
```

### Archivo: `./ex01/Phoneook.hpp`
```hpp
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
```

### Archivo: `./ex01/Contact.cpp`
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

