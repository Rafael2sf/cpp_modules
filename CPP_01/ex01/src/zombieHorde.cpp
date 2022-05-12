/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:42:06 by rafernan          #+#    #+#             */
/*   Updated: 2022/05/12 10:54:43 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int n, std::string name )
{
	Zombie	*horde;

	if (n <= 0)
		return (NULL);
	Zombie::default_name = name;
	horde = new Zombie[n];
	Zombie::default_name = "zombie";
	return (horde);
}
