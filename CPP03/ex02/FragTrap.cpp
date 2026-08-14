#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;

	std::cout << "FragTrap default constructor called for " << _name << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;

	std::cout << "FragTrap constructor called for " << _name << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy) {
	*this = copy;
	std::cout << "FragTrap " << _name << " copied" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &copy) {
	if (this != &copy) {
		this->_name = copy._name;
		this->_hitPoints = copy._hitPoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackDamage = copy._attackDamage;
	}
	return *this; 
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _name << " has been destroyed!" << std::endl;
}

void FragTrap::highFivesGuys(){
	std::cout << "High five!" << std::endl;
}