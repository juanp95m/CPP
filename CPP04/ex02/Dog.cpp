#include "Dog.hpp"

Dog::Dog() : AAnimal() {
	this->ObjBrain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& copy) : AAnimal(copy) {
	std::cout << "Dog copy constructor called" << std::endl;
	this->ObjBrain = new Brain(*copy.ObjBrain);
}

Dog& Dog::operator=(const Dog& copy) {
	if (this != &copy){
		AAnimal::operator=(copy);
		*this->	ObjBrain = *copy.ObjBrain;
	}
	return *this;
}

Dog::~Dog(){
	std::cout << "Dog destructor called" << std::endl;
	delete this->ObjBrain;
}

void Dog::makeSound() const {
	std::cout << "Esteeeee Guaaauu" << std::endl;
}