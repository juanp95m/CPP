#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap {
	
	protected:
		std::string	_name;
		unsigned int _hitPoints;
		unsigned int _energyPoints;
		unsigned int _attackDamage;
	public:

		ClapTrap();
		ClapTrap(const std::string &name); // constructor parametrizado
		ClapTrap(const ClapTrap &copy); // constructor de copia
		ClapTrap &operator=(const ClapTrap &copy); // operador de asignacion
		~ClapTrap();

		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};


#endif