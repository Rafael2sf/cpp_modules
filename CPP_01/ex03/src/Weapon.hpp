#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class	Weapon
{
	public:
		Weapon( void );
		~Weapon();
		std::string & const getType( void ) const;
		void setType( std::string & const );

	private:
		std::string _type;
};

#endif /* WEAPON_HPP */
