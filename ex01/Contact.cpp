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