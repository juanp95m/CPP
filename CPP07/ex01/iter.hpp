#ifndef ITER_HPP
# define ITER_HPP

# include <string>
# include <iostream>
# include <cstddef>

template <typename T, typename F>
void iter(T *array, const std::size_t length, F f){
	if (!array || !f)
		return ;
	for (size_t i = 0; i < length; i++)
		f(array[i]);
}


#endif