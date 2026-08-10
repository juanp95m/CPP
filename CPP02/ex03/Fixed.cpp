#include "Fixed.hpp"
/*
Es el constructor por defecto. Crea un objeto con valor 0 y deja el atributo 
interno inicializado en 0. Sirve cuando haces algo como Fixed a;
*/
Fixed::Fixed() : _fixedPointValue(0) {}

/*
Es el constructor de copia. Crea un objeto nuevo copiando el contenido de otro 
objeto Fixed. Se usa cuando inicializas un objeto a partir de otro, como Fixed b(a)
*/
Fixed::Fixed(const Fixed &other) {
	*this = other;
}

/*
Es el operador de asignación. Sirve para copiar el valor de un objeto ya existente 
sobre otro ya creado, como c = a;. Primero comprueba que no sea autoasignación y 
luego copia el valor interno
*/
Fixed &Fixed::operator=(const Fixed &other) {
	if (this != &other)
		this->_fixedPointValue = other._fixedPointValue;
	return *this;
}


/*
Es el destructor. Se ejecuta cuando el objeto deja de existir.
*/
Fixed::~Fixed() {}


/*
Constructor que recibe un entero. Convierte ese entero al formato fixed-point 
moviendo el valor 8 bits a la izquierda. Por ejemplo, 10 pasa a almacenarse como 10 × 256.
*/
Fixed::Fixed(const int value) {
	this->_fixedPointValue = value << _fractionalBits;
}


/*
Constructor que recibe un float. Convierte el decimal al formato fixed-point multiplicando 
por 256 y redondeando al entero más cercano. Así puedes crear objetos como Fixed c(42.42f);
*/
Fixed::Fixed(const float value) {
	this->_fixedPointValue = static_cast<int>(roundf(value * (1 << _fractionalBits)));
}


/*
Devuelve el valor interno crudo, sin convertirlo a entero normal ni a float. 
Sirve para inspeccionar directamente lo que está guardado en _fixedPointValue.
*/
int Fixed::getRawBits(void) const {
	return this->_fixedPointValue;
}

/*
Cambia directamente el valor interno crudo. Es un setter bajo nivel.
*/
void Fixed::setRawBits(int const raw) {
	this->_fixedPointValue = raw;
}


/*
Convierte el valor almacenado al número decimal real. Divide el entero interno 
entre 256 y devuelve un float.
*/
float Fixed::toFloat(void) const {
	return static_cast<float>(this->_fixedPointValue) / (1 << _fractionalBits);
}

/*
Convierte el valor almacenado a entero truncando la parte fraccionaria. 
Básicamente elimina los 8 bits fraccionales.
*/
int Fixed::toInt(void) const {
	return this->_fixedPointValue >> _fractionalBits;
}

/*
Es el operador de salida para poder imprimir un objeto Fixed con std::cout. 
En vez de mostrar el valor crudo, imprime el resultado de toFloat().
*/
std::ostream &operator<<(std::ostream &out, const Fixed &value) {
	out << value.toFloat();
	return out;
}


bool Fixed::operator>(const Fixed &other) const {
	return (this->_fixedPointValue > other._fixedPointValue);
}

bool Fixed::operator<(const Fixed &other) const {
	return (this->_fixedPointValue < other._fixedPointValue);
}

bool Fixed::operator>=(const Fixed &other) const {
	return (this->_fixedPointValue >= other._fixedPointValue);
}

bool Fixed::operator<=(const Fixed &other) const {
	return (this->_fixedPointValue <= other._fixedPointValue);
}

bool Fixed::operator==(const Fixed &other) const{
	return (this->_fixedPointValue == other._fixedPointValue);
}

bool Fixed::operator!=(const Fixed &other) const {
	return (this->_fixedPointValue != other._fixedPointValue);
}

Fixed Fixed::operator+(const Fixed &other) const {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator++(){
	++_fixedPointValue;
	return *this;
}

Fixed Fixed::operator++(int){
	Fixed temp(*this);
	++(*this);
	return temp;
}

Fixed &Fixed::operator--(){
	--_fixedPointValue;
	return *this;
}

Fixed Fixed::operator--(int){
	Fixed temp(*this);
	--(*this);
	return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b){
	return a < b ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b){
	return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b){
	return a > b ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b){
	return a > b ? a : b;
}