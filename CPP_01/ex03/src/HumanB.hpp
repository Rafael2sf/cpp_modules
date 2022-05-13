#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include <iostream>
# include "Weapon.hpp"

class	HumanB
{
	public:
		~HumanB();
		HumanB( std::string );
		void setWeapon( Weapon & );
		std::string getName( void ) const;
		void setName( std::string );
		std::string getType( void ) const;
		void setType( std::string );
		void attack( void ) const;

	private:
		Weapon * _weapon;
		std::string _name;
};

#endif /* HUMANB_HPP */
