#include "Zombie.hpp"

int main(void)
{
	Zombie *Foo1  = newZombie("Foo");
	Foo1->anounce();
	randomChump("Boo");
	delete Foo1;
	return 0;
}