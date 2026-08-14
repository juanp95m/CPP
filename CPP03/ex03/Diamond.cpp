#include "Diamond.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("DefaultClapName"), FragTrap(), ScavTrap(),  _name("Deafault"){

	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;

	std::cout << "DiamondTrap Default created" << std::endl;
}

