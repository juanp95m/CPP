#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

template <typename T>
class Array {
private:
	T*              _elements;
	unsigned int    _size;

public:
	// 1. Constructor por defecto: crea un array vacío
	Array() : _elements(NULL), _size(0) {}

	// 2. Constructor con parámetro: crea n elementos inicializados por defecto
	Array(unsigned int n) : _elements(NULL), _size(n) {
		if (n > 0)
			_elements = new T[n](); // Los paréntesis () fuerzan el valor por defecto (0, false, etc.)
	}

	// 3. Constructor de copia: deep copy
	Array(const Array &other) : _elements(NULL), _size(0) {
		*this = other;
	}

	// 4. Destructor: libera memoria con delete[]
	~Array() {
		if (_elements)
			delete[] _elements;
	}

	// 5. Operador de asignación: deep copy
	Array &operator=(const Array &other) {
		if (this != &other) {
			if (_elements)
				delete[] _elements;
			_size = other._size;
			if (_size > 0) {
				_elements = new T[_size];
				for (unsigned int i = 0; i < _size; ++i)
					_elements[i] = other._elements[i];
			} else {
				_elements = NULL;
			}
		}
		return *this;
	}

	// 6. Operador de indexación [] (no const)
	T &operator[](unsigned int index) {
		if (index >= _size)
			throw std::out_of_range("Array: index out of bounds");
		return _elements[index];
	}

	// 7. Operador de indexación [] (const)
	const T &operator[](unsigned int index) const {
		if (index >= _size)
			throw std::out_of_range("Array: index out of bounds");
		return _elements[index];
	}

	// 8. Función miembro size()
	unsigned int size() const {
		return _size;
	}
};

#endif