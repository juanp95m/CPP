#include "Zombie.hpp"

Zombie* newZombie(std::string name){
	Zombie* zombieHeap = new Zombie(name);
	return zombieHeap;
}