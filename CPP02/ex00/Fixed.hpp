#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	private:
	int _fixedPointValue;
	static const int _fractionalBits = 8;

	public:
	Fixed();                                 // Constructor por defecto
	Fixed(const Fixed &other);               // Constructor de copia
	Fixed &operator=(const Fixed &other);    // Operador de asignación
	~Fixed();                                // Destructor
	int getRawBits(void) const;
	void setRawBits(int const raw);

};

#endif