#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	// Forma Canónica Ortodoxa
	MutantStack() : std::stack<T>() {}
	MutantStack(const MutantStack<T> &copy) : std::stack<T>(copy) {}
	MutantStack<T> &operator=(const MutantStack<T> &copy)
	{
		if (this != &copy)
			std::stack<T>::operator=(copy);
		return *this;
	}
	virtual ~MutantStack() {}

	// Alias para los tipos de iteradores
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

	// Métodos de iteración
	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }

	const_iterator begin() const { return this->c.begin(); }
	const_iterator end() const { return this->c.end(); }
};

#endif