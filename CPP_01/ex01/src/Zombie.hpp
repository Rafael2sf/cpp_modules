/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:42:17 by rafernan          #+#    #+#             */
/*   Updated: 2022/05/12 15:58:25 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie
{
	public:
		Zombie( void );
		Zombie( std::string );
		~Zombie( void );

		static std::string	default_name;
		void setName( std::string );
		void announce( void );
	private:
		std::string _name;
};

Zombie*		zombieHorde( int N, std::string name );

#endif
