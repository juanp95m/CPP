#include "DiamondTrap.hpp"

int main(void) {
	std::cout << "--- CREATING DIAMONDTRAP ---" << std::endl;
	DiamondTrap monster("Dracula");

	std::cout << "\n--- TESTING WHOAMI ---" << std::endl;
	monster.whoAmI();

	std::cout << "\n--- TESTING ATACK (FROM SCAVTRAP) ---" << std::endl;
	monster.attack("Target");

	std::cout << "\n--- DESTRUCTION ---" << std::endl;
	return 0;
}