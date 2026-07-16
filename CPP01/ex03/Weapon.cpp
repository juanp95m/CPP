#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type){}

Weapon::~Weapon(){}

const std::string &Weapon::getType(void) const{
    return _type;
}

void setType(std::string newType){
    _type = newType;
}