#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"


class DiamondTrap : public FragTrap, public ScavTrap {

	private:
		std::string _name; // Atributo propio con el mismo nombre que el de ClapTrap

	public:
		DiamondTrap();
		DiamondTrap(const std::string &name);
		DiamondTrap(const DiamondTrap &copy);
		DiamondTrap &operator=(const DiamondTrap &copy);
		~DiamondTrap();

		using ScavTrap::attack; // Usa el ataque específico de ScavTrap
		void whoAmI();

};

#endif