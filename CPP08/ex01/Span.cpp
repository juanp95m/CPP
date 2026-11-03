# include "Span.hpp"

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int N) : _maxSize(N) {}

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
	if (_numbers.size() < 2)
		throw std::logic_error("Not enough elements to calculate span");
	return *(--_numbers.end()) - *_numbers.begin();
}

#include <climits>

int Span::shortestSpan() const {
	if (_numbers.size() < 2)
		throw std::logic_error("Not enough elements to calculate span");

	int minDistance = INT_MAX;

	std::multiset<int>::const_iterator it = _numbers.begin();
	std::multiset<int>::const_iterator next = it;
	++next;

	while (next != _numbers.end()) {
		int diff = *next - *it;
		if (diff < minDistance)
			minDistance = diff;
		++it;
		++next;
	}

	return minDistance;
}

