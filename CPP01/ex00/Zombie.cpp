#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {}

Zombie::~Zombie() {
    std::cout << _name << ": " << "dieeeed" << std::endl;
}

void Zombie::anounce() {
    std::cout << _name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

