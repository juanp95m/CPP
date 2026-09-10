#include "Animal.hpp"

Animal::Animal() : _type("Animal"){
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& copy) : _type(copy._type) {
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& copy) {
	std::cout << "Animal copy assigment operator called" << std::endl;
	if (this != &copy)
		this->_type = copy._type;
	return *this;
}

Animal::~Animal(){
	std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const {
	std::cout << "--Soy un animalito no se aun si soy perrito o gatito--" << std::endl;
}

std::string Animal::getType() const {
	return this->_type;
}