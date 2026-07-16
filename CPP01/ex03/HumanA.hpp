#ifndef HUMANA_HPP
# define HUMANA_HPP_HPP

#include "Weapon.hpp"

class HumanA {
	private:
	std::string _name;
	Weapon &_weapon;                       // El arma se guarda como REFERENCIA
	public:
	HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon){}  // El constructor requiere el arma ya inicializada
	~HumanA();

	void attack(void);                         // Metodo para atacar

};

#endif