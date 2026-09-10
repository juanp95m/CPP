#include "Cat.hpp"

Cat::Cat() : Animal() {
	this->ObjBrain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& copy) : Animal(copy) {
	std::cout << "Cat copy constructor called" << std::endl;
	this->ObjBrain = new Brain(*copy.ObjBrain);
}

Cat& Cat::operator=(const Cat& copy) {
	if (this != &copy){
		Animal::operator=(copy);
		*this->ObjBrain = *copy.ObjBrain;
	}
	return *this;
}

Cat::~Cat(){
	std::cout << "Cat destructor called" << std::endl;
	delete this->ObjBrain;
}

void Cat::makeSound() const {
	std::cout << "Esteeeee Miaaauu" << std::endl;
}