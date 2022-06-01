#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class	ClapTrap
{
	public:
		~ClapTrap();
		ClapTrap( ClapTrap const & );
		ClapTrap( std::string const );

		ClapTrap & operator=( ClapTrap const & );

		void	attack( std::string const & );
		void	takeDamage( unsigned int );
		void	beRepaired( unsigned int );

	private:
		ClapTrap( void );
		std::string	_name;
		int	_hp;
		int	_ep;
		int	_ad;
};

#endif /* CLAPTRAP_HPP */
