#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap
{
	public:
		~FragTrap();
		FragTrap( FragTrap const & );
		FragTrap( std::string const );

		FragTrap & operator=( FragTrap const & );

		void	attack( std::string const & );
		void	highFivesGuys( void );

	protected:
		FragTrap();
};

#endif /* FRAGTRAP_HPP */
