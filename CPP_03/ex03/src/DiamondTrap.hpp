#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include <string.h>
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class	DiamondTrap : public FragTrap, public ScavTrap
{
	public:
		~DiamondTrap();
		DiamondTrap( std::string name );
		DiamondTrap( DiamondTrap const & );
		DiamondTrap & operator=( DiamondTrap const & );
		void	whoAmI( void );
		void	attack( std::string const & );
	private:
		DiamondTrap( void );
		std::string _name;
};

#endif /* DIAMONDTRAP_HPP */
