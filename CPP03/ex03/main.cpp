#include "DiamondTrap.hpp"

int main()
{
	std::cout << "--- 1. CONSTRUCCION (UN SOLO CLAPTRAP) ---" << std::endl;
	DiamondTrap monster("Monster");

	std::cout << "\n--- 2. IDENTIDAD WHOAMI ---" << std::endl;
	monster.whoAmI(); // Imprime Monster y Monster_clap_name

	std::cout << "\n--- 3. ATAQUE HEREDADO DE SCAVTRAP ---" << std::endl;
	monster.attack("target"); // Mensaje de ScavTrap con dano de FragTrap (30)

	std::cout << "\n--- 4. HABILIDADES COMBINADAS DE AMBOS PADRES ---" << std::endl;
	monster.guardGate();      // De ScavTrap
	monster.highFivesGuys();  // De FragTrap

	std::cout << "\n--- 5. CADENA DE DESTRUCCION INVERSA ---" << std::endl;
	return 0;
}