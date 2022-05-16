/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:42:32 by rafernan          #+#    #+#             */
/*   Updated: 2022/05/16 23:39:02 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int main(void)
{
	Zombie	zombie_a = Zombie("zombieA");
	zombie_a.announce();
	
	randomChump("zombieB");

	Zombie *zombie_c = newZombie("zombieC");
	zombie_c->announce();
	delete zombie_c;

	return (0);
}
