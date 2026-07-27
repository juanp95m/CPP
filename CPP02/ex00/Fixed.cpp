#include "Fixed.hpp"


// 1. Constructor
Fixed::Fixed() : _fixedPointValue(0){
	std::cout << "Default constructor called" << std::endl;
}


// 2. Constructor de copia
Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// 3. Operador de asignación
Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_fixedPointValue = other.getRawBits();
	}
	return *this;
}

// 4. Destructer
Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

// 5. Getter
int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointValue;
}

// 6. setter
void Fixed::setRawBits(int const raw) {
	this->_fixedPointValue = raw;
}