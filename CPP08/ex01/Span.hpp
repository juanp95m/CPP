#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>


# include <stdexcept>

# include <iterator>
# include <iostream>
# include <set>


class Span {
	
	private:
		unsigned int 		_maxSize;
		std::multiset<int> 	_numbers;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span &copy);
		Span &operator=(const Span &copy);
		~Span();

		void addNumber(int number);
		int shortestSpan() const;
		int longestSpan() const;

		// Función plantilla para añadir un rango de elementos
		template <typename InputIterator>
		void addRange(InputIterator begin, InputIterator end)
		{
		// Comprobamos la distancia del rango a insertar
		if (_numbers.size() + std::distance(begin, end) > _maxSize)
			throw std::out_of_range("Adding this range exceeds the maximum capacity of Span");
		_numbers.insert(begin, end);
		}

};

#endif