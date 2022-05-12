/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:42:32 by rafernan          #+#    #+#             */
/*   Updated: 2022/05/11 15:42:33 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int main(void)
{
	Zombie	zombie_a = Zombie("zombie_a");
	zombie_a.announce();
	
	randomChump("zombie_b");

	Zombie *zombie_c = newZombie("zombie_c");
	zombie_c->announce();
	delete zombie_c;

	return (0);
}
