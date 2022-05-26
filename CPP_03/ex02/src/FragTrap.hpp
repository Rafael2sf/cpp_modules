#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class	FragTrap : public ClapTrap
{
	public:
		~FragTrap();
		FragTrap( FragTrap const & );
		FragTrap( std::string const );

		FragTrap & operator=( FragTrap const & );

		void	attack( std::string const & );
		void	highFivesGuys( void );

	private:
		FragTrap();
};

#endif /* FRAGTRAP_HPP */
