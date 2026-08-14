#include "FragTrap.hpp"

int main (void) {
	
	FragTrap frag("Fraggy");

	frag.attack("Target");
	frag.takeDamage(50);
	frag.beRepaired(20);
	frag.highFivesGuys();

	return (0);

}