#include "ClapTrap.hpp"

int main(void){
	ClapTrap clapitrapi("robotito");
	std::string enemy;

	clapitrapi.attack("enemy");

	clapitrapi.takeDamage(5);

	clapitrapi.beRepaired(3);

	clapitrapi.takeDamage(20);

	clapitrapi.attack("enemy");

	return 0;
}