#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>


// La clase contact será la clase que contenga la información de un solo usuario
// y las funciones para interactuar con esos datos individuales. 
// (nombre, apellido, secreto, etc.)
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
	
	std::string getFirstName(void) const;               // getters
	std::string getLastName(void) const;                //
	std::string getNickName(void) const;                // cogen la info
	std::string getPhoneNumber(void) const;             // y la muestran
	std::string getDarkestSecret(void) const;           //---------
	void	setFirstName(std::string firstName);        // setters
	void	setLastName(std::string lastName);          // 
	void	setNickName(std::string nickName);          // puede modificar
	void	setPhoneNumber(std::string phoneNumber);    // la info (los atributos)
	void	setDarkestSecret(std::string darkestSecret);//
};

#endif