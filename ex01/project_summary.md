# Resumen del Proyecto: ex01
Generado el: 2026-06-11 17:03:42

## Estructura de Archivos Incluidos
```
  - ./Makefile
  - ./Contact.hpp
  - ./Phoneook.hpp
```

## Contenido de los Archivos

### Archivo: \`./Makefile\`
\`\`\`/Makefile
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
\`\`\`

### Archivo: \`./Contact.hpp\`
\`\`\`hpp
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
	
	void setFirstName(std::string firstName);
	void setLastName(std::string lastName);
	void setNickName(std::string nickName);
	void setPhoneNumber(std::string phoneNumber);
	void setDarkestSecret(std::string darkestSecret);
	std::string getFirstName(void) const;

};
#endif
\`\`\`

### Archivo: \`./Phoneook.hpp\`
\`\`\`hpp
#include "Contact.hpp"

class Phonebook {
private:
	Contact	_contacts[8];
	int		_index;

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
\`\`\`

