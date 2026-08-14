#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

	public:
	// 1. Forma Canónica Ortodoxa + Constructor Parametrizado
		ScavTrap();
		ScavTrap(const std::string &name);
		ScavTrap(const ScavTrap &copy);
		ScavTrap &operator=(const ScavTrap &copy);
		~ScavTrap();

	// 2. Sobrescribir el método de ataque (porque ScavTrap imprime un mensaje diferente)
		void attack(const std::string &target);
	// 3. Habilidad especial propia de ScavTrap
		void guardGate();
};

#endif