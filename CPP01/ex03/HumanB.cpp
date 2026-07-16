#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(0) {}

HumanB::~HumanB(){}

void HumanB::setWeapon(Weapon &weapon){
    _weapon = &weapon;
}

void HumanB::attack(void){
    if (_weapon != 0)
        std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}