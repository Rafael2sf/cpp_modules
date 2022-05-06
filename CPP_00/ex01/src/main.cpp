/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:23:28 by rafernan          #+#    #+#             */
/*   Updated: 2022/05/06 12:26:10 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(void)
{
	PhoneBook	phone_book = PhoneBook();
	std::string	opt = "";

	while (1)
	{
		std::cout << "Phonebook {ADD, SEARCH, EXIT}\n: ";
		std::getline(std::cin, opt);
		if (std::cin.eof() || std::cin.fail())
			return (0);
		else if (opt == "ADD")
			phone_book.setContact();
		else if (opt == "SEARCH")
			phone_book.search();
		else if (opt == "EXIT")
			break ;
	}
	return (0);
}
