/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:42:22 by rafernan          #+#    #+#             */
/*   Updated: 2022/05/12 15:58:48 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int main(void)
{
	Zombie	*horde;
	int		i;

	i = 0;
	horde = zombieHorde(10, "creep");
	while (i < 10)
		horde[i++].announce();
	delete[] horde;
	return (0);
}
