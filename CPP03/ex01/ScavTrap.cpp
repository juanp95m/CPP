#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;

	std::cout << "ScavTrap default constructor called for " << _name << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;

	std::cout << "ScavTrap constructor called for " << _name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap() {
	*this = copy;
	std::cout << "ScavTrap " << _name << " copied" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy){
	if (this != &copy) {
		this->_name = copy._name;
		this->_hitPoints = copy._hitPoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackDamage = copy._attackDamage;
	}
	return *this;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap " << _name << " has been destroyed!" << std::endl;
}

void ScavTrap:: attack(const std::string &target) {
	if (_hitPoints == 0 || _energyPoints == 0){
		std::cout << "ScavTrap " << _name  << "without energy or life" <<std::endl; 
	}
	else {
		_energyPoints--;
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;

	}
}


void ScavTrap::guardGate() {
	std::cout  << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
}