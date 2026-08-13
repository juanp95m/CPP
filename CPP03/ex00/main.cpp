#include "ClapTrap.hpp"

int main(void){
	ClapTrap clapitrapi("robotito");
	std::string enemie;

	clapitrapi.attack("enemie");

	clapitrapi.takeDamage(5);

	clapitrapi.beRepaired(3);

	clapitrapi.takeDamage(20);

	clapitrapi.attack("enemie");

	return 0;
}