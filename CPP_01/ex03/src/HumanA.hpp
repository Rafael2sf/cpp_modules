#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include <iostream>
# include "Weapon.hpp"

class	HumanA
{
	public:
		~HumanA();
		HumanA( std::string const, Weapon & );
		std::string getName( void ) const;
		void setName( std::string );
		std::string getType( void ) const;
		void setType( std::string );
		void attack( void ) const;

	private:
		std::string _name;
		Weapon & _weapon;
};

#endif /* HUMANA_HPP */
