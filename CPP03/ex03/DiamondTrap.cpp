#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_Clap_Name"), FragTrap(), ScavTrap(),  _name("Deafault"){

	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;

	std::cout << "DiamondTrap Default created" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_Clap_Name"), FragTrap(name), ScavTrap(name), _name(name){

	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;

	std::cout << "DiamondTrap " << _name << " created" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), FragTrap(copy), ScavTrap(copy) {
	
	*this = copy;
	std::cout << "DiamondTrap " << _name << " copied" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy){
	if (this != &copy) {
		this->_name = copy._name;
		this->_hitPoints = copy._hitPoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackDamage = copy._attackDamage;
		ClapTrap::_name = copy.ClapTrap::_name;
	}
	return *this;
}

DiamondTrap::~DiamondTrap(){
	std::cout << "DiamondTrap " << _name << " Destroyed" << std::endl;
}

void DiamondTrap::whoAmI(){
	std::cout << "My DiamondTrap name is: " << _name << std::endl;
	std::cout << "My ClapTrap name is: " << ClapTrap::_name << std::endl;
}