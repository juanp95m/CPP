# Resumen del Proyecto: CPP02
Generado el: 2026-08-27 17:35:51

## Estructura de Archivos Incluidos
```
  - CPP02/ex00/Fixed.cpp
  - CPP02/ex00/main.cpp
  - CPP02/ex01/Fixed.cpp
  - CPP02/ex01/main.cpp
  - CPP02/ex02/Fixed.cpp
  - CPP02/ex02/main.cpp
  - CPP02/ex03/BSP.cpp
  - CPP02/ex03/Fixed.cpp
  - CPP02/ex03/Point.cpp
  - CPP02/ex03/main.cpp
```

## Contenido de los Archivos

### Archivo: `CPP02/ex00/Fixed.cpp`
```cpp
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
```

### Archivo: `CPP02/ex00/main.cpp`
```cpp
#include "Fixed.hpp"

int main (void)
{
	Fixed a;
	Fixed b(a);
	Fixed c;

	c = a;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	
	return 0;
}
```

### Archivo: `CPP02/ex01/Fixed.cpp`
```cpp
#include "Fixed.hpp"
/*
Es el constructor por defecto. Crea un objeto con valor 0 y deja el atributo 
interno inicializado en 0. Sirve cuando haces algo como Fixed a;
*/
Fixed::Fixed() : _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

/*
Es el constructor de copia. Crea un objeto nuevo copiando el contenido de otro 
objeto Fixed. Se usa cuando inicializas un objeto a partir de otro, como Fixed b(a)
*/
Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

/*
Es el operador de asignación. Sirve para copiar el valor de un objeto ya existente 
sobre otro ya creado, como c = a;. Primero comprueba que no sea autoasignación y 
luego copia el valor interno
*/
Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_fixedPointValue = other._fixedPointValue;
	return *this;
}


/*
Es el destructor. Se ejecuta cuando el objeto deja de existir.
*/
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}


/*
Constructor que recibe un entero. Convierte ese entero al formato fixed-point 
moviendo el valor 8 bits a la izquierda. Por ejemplo, 10 pasa a almacenarse como 10 × 256.
*/
Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = value << _fractionalBits;
}


/*
Constructor que recibe un float. Convierte el decimal al formato fixed-point multiplicando 
por 256 y redondeando al entero más cercano. Así puedes crear objetos como Fixed c(42.42f);
*/
Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
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

```

### Archivo: `CPP02/ex01/main.cpp`
```cpp
#include "Fixed.hpp"

int main (void)
{
    Fixed a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);

    a = Fixed(1234.43f);

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    return (0);
}
```

### Archivo: `CPP02/ex02/Fixed.cpp`
```cpp
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
	std::cout << "Copy assignment operator called" << std::endl;
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
```

### Archivo: `CPP02/ex02/main.cpp`
```cpp
#include "Fixed.hpp"

int main( void ) {
	Fixed		a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << b << std::endl;
	
	std::cout << Fixed::max( a, b ) << std::endl;
	
	return 0;
}
```

### Archivo: `CPP02/ex03/BSP.cpp`
```cpp
#include "Point.hpp"


// Función auxiliar para calcular el producto cruzado 2D
static Fixed area(Point const p1, Point const p2, Point const p) {
	return (p1.getX() - p.getX()) * (p2.getY() - p.getY()) - (p2.getX() - p.getX()) * (p1.getY() - p.getY());
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed d1 = area(a, b, point);
	Fixed d2 = area(b, c, point);
	Fixed d3 = area(c, a, point);

	// Si algún resultado es 0, el punto está en un borde o vértice -> false
	if (d1 == 0 || d2 == 0 || d3 == 0)
		return false;

	// Comprobamos si las 3 orientaciones tienen el mismo signo
	bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

	// Si no tiene mezcla de positivos y negativos, está estrictamente dentro
	return !(has_neg && has_pos);
}


```

### Archivo: `CPP02/ex03/Fixed.cpp`
```cpp
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
```

### Archivo: `CPP02/ex03/Point.cpp`
```cpp
#include "Point.hpp"

Point::Point() : _x(0), _y(0){}

Point::Point(const Point &other) : _x(other._x), _y(other._y){}

Point::Point(const float x, const float y) : _x(x), _y(y){}

Point &Point::operator=(const Point &other){
	(void)other;
	return *this;
}

Fixed Point::getX() const {
	return this->_x;
}

Fixed Point::getY() const {
	return this->_y;
}

Point::~Point(){}
```

### Archivo: `CPP02/ex03/main.cpp`
```cpp
#include "Point.hpp"

int main(void) {
    // Definimos los 3 vértices del triángulo ABC
    Point const a(0.0f, 0.0f);
    Point const b(10.0f, 0.0f);
    Point const c(0.0f, 10.0f);

    // 1. Punto DENTRO del triángulo
    Point const inside(2.0f, 2.0f);
    
    // 2. Punto FUERA del triángulo
    Point const outside(12.0f, 5.0f);
    
    // 3. Punto en un VÉRTICE (ej. exactamente en el vértice A)
    Point const vertex(0.0f, 0.0f);
    
    // 4. Punto en un EDGE / BORDE (ej. en medio del segmento A-B)
    Point const edge(5.0f, 0.0f);

    std::cout << "--- TEST BSP ---" << std::endl;
    std::cout << "Inside  (2, 2):   " << (bsp(a, b, c, inside)  ? "IN" : "OUT") << std::endl;
    std::cout << "Outside (12, 5):  " << (bsp(a, b, c, outside) ? "IN" : "OUT") << std::endl;
    std::cout << "Vertex  (0, 0):   " << (bsp(a, b, c, vertex)  ? "IN" : "OUT") << std::endl;
    std::cout << "Edge    (5, 0):   " << (bsp(a, b, c, edge)    ? "IN" : "OUT") << std::endl;

    return 0;
}
```

