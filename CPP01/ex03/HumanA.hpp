#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
	private:
	std::string _name;
	Weapon &_weapon;                        // El arma se guarda como REFERENCIA
	public:
	HumanA(std::string name, Weapon &weapon); // El constructor requiere el arma 
	~HumanA();

	void attack(void);                       // Metodo para atacar

};

#endif