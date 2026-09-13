#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal"){
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& copy) : _type(copy._type) {
	std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& copy) {
	std::cout << "AAnimal copy assigment operator called" << std::endl;
	if (this != &copy)
		this->_type = copy._type;
	return *this;
}

AAnimal::~AAnimal(){
	std::cout << "AAnimal destructor called" << std::endl;
}

std::string AAnimal::getType() const {
	return this->_type;
}