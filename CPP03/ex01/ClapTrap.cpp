#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0){
	std::cout << "ClapTrap " << _name << " has been created!" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0){
	std::cout << "ClapTrap " << _name << " has been created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
	*this = copy;
	std::cout << "ClapTrap " << _name << "copied!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy) {
	if (this != &copy) { // evitamos la autoasignacion (a = a)
		this->_name	= copy._name;
		this->_hitPoints = copy._hitPoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackDamage = copy._attackDamage;
	}
	return *this;
}

void ClapTrap::attack(const std::string &target) {
	if (_hitPoints == 0)
		std::cout << "ClapTrap " << _name  << " It has no life, so it cannot attack" << std::endl;
	else if (_energyPoints == 0)
		std::cout << "ClapTrap " << _name  << " It has no energy, so it cannot attack" << std::endl;
	else {
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints <= 0)
		std::cout << "ClapTrap " << _name << " It has no life, so it cannot be repaired" << std::endl;
	else if (_energyPoints <= 0)
		std::cout << "ClapTrap " << _name << " It has no energy, so it cannot be reparired" << std::endl;
	else if (_hitPoints > 0 && _energyPoints > 0) {
		_energyPoints--;
		_hitPoints += amount;
		std::cout << "ClapTrap " << _name << " Has been repaired" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " is already dead" << std::endl;
		return;
	}
	if (amount >= _hitPoints) {
		_hitPoints = 0;
		std::cout << "ClapTrap " << _name << " is dead" << std::endl;
	}
	else
		_hitPoints -= amount;
	std::cout << "ClapTrap " << _name << " takes " << amount << " Points of damage!" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " has been destroyed!" <<std::endl;
}