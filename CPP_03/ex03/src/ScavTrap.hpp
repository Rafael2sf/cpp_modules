#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class	ScavTrap : virtual public ClapTrap
{
	public:
		~ScavTrap();
		ScavTrap( ScavTrap const & );
		ScavTrap( std::string const );

		ScavTrap & operator=( ScavTrap const & );

		void	attack( std::string const & );
		void	GuardGate( void );

	protected:
		ScavTrap();
};

#endif /* SCAVTRAP_HPP */
