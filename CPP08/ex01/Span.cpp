# include "Span.hpp"

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int N) : _maxSize(_maxSize) {}

Span::Span(const Span &copy) : _maxSize(copy._maxSize), _numbers(copy._numbers) {}

Span &Span::operator=(const Span &copy) {
	if (this != &copy) {
		this->_maxSize = copy._maxSize;
		this->_numbers = copy._numbers;
	}
	return *this;

}

Span::~Span(){}

void Span::addNumber(int number) {
	if (_numbers.size() >= _maxSize)
		throw std::out_of_range("Out of range");
	else
		_numbers.insert(number);
}

int Span::longestSpan() const {
	if (_maxSize < 2)
		throw
}

