#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();


	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;

	j->makeSound();
	i->makeSound(); //will output the cat sound!
	meta->makeSound();

	std::cout << std::endl;
	std::cout << "****Testing Wrong classes****" << std::endl;
	const WrongAnimal* beta = new WrongCat();
	std::cout << beta->getType() << "-> type of beta" << std::endl;
	beta->makeSound();

	delete j;
	delete i;
	delete meta;
	delete beta;
	return 0;
}