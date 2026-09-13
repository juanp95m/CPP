#include "Cat.hpp"

Cat::Cat() : AAnimal() {
	this->ObjBrain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& copy) : AAnimal(copy) {
	std::cout << "Cat copy constructor called" << std::endl;
	this->ObjBrain = new Brain(*copy.ObjBrain);
}

Cat& Cat::operator=(const Cat& copy) {
	if (this != &copy){
		AAnimal::operator=(copy);
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