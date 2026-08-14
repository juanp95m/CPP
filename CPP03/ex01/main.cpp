#include "ScavTrap.hpp"

int main (void) {
	
	ScavTrap scav("scavy");

	scav.attack("Bandido");
	scav.takeDamage(30);
	scav.beRepaired(10);
	scav.guardGate();

	return (0);

}