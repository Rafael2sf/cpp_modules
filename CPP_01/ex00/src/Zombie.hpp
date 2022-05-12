/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:42:24 by rafernan          #+#    #+#             */
/*   Updated: 2022/05/11 15:42:25 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie
{
	public:
		Zombie( std::string );
		~Zombie( void );

		void announce( void );
	private:
		std::string _name;
};

Zombie*	newZombie( std::string name );
void 	randomChump( std::string name );

#endif
