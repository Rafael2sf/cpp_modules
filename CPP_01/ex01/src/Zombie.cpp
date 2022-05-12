/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:27:05 by rafernan          #+#    #+#             */
/*   Updated: 2022/05/12 15:57:19 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie( void ): _name(default_name)
{}

Zombie::Zombie( std::string name ) : _name(name)
{}

Zombie::~Zombie( void )
{
	std::cout << this->_name << ": is no longer between us...\n";
}

void Zombie::setName( std::string name)
{
	Zombie::_name = name;
}

void Zombie::announce( void )
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ...\n";
}

std::string	Zombie::default_name = "zombie";
