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
/*
Fixed x(10);
Fixed y(5);

std::cout << "x > y: " << (x > y) << std::endl;
std::cout << "x < y: " << (x < y) << std::endl;
std::cout << "x >= y: " << (x >= y) << std::endl;
std::cout << "x <= y: " << (x <= y) << std::endl;
std::cout << "x == y: " << (x == y) << std::endl;
std::cout << "x != y: " << (x != y) << std::endl;

std::cout << "x + y: " << x + y << std::endl;
std::cout << "x - y: " << x - y << std::endl;
std::cout << "x * y: " << x * y << std::endl;
std::cout << "x / y: " << x / y << std::endl;

std::cout << "min: " << Fixed::min(x, y) << std::endl;
std::cout << "max: " << Fixed::max(x, y) << std::endl;
*/