/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:00:56 by rafernan          #+#    #+#             */
/*   Updated: 2022/05/16 22:59:10 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

static std::string	strunc(std::string str, size_t size);
static std::string	prompt(std::string str);

PhoneBook::PhoneBook(void) : _n(0)
{}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Bye, bye... Have a wonderfull day\n";
}

void PhoneBook::setContact(void)
{
	Contact	tmp;
	int	pos;

	pos = (this->_n);
	if (pos >= 8)
		pos %= 8;
	(tmp.first_name) = prompt("firstname $ ");
	(tmp.last_name) = prompt("lastname $ ");
	(tmp.nick_name) = prompt("nickname $ ");
	(tmp.number) = prompt("number $ ");
	(tmp.dark_secret) = prompt("dark secret $ ");
	if (!tmp.isValidContact())
	{
		std::cerr << "error: empty field is not valid" << std::endl;
		return ;
	}
	(this->_contacts[pos]) = tmp;
	(this->_n) += 1;
	if (this->_n == 16)
		(this->_n) -= 8;
}

void PhoneBook::getContact(int index) const
{
	if (index < 0 || index > 7)
	{
		std::cerr << "error: out of range index" << std::endl;
		return ;
	}
	if ((this->_n) <= index)
	{
		std::cerr << "error: unset contact" << std::endl;
		return ;
	}
	std::cout << "\nfirstname:\t" << (this->_contacts[index].first_name) << ",\n";
	std::cout << "lastname:\t" << (this->_contacts[index].last_name) << ",\n";
	std::cout << "nickname:\t" << (this->_contacts[index].nick_name) << ",\n";
	std::cout << "number:\t\t" << (this->_contacts[index].number) << ",\n";
	std::cout << "dark secret:\t" << (this->_contacts[index].dark_secret) << "\n\n";
}

void PhoneBook::search(void) const
{
	int			i = 0;
	std::string	tmp;

	std::cout << std::string(45, '_') << std::endl;
	while (i < (this->_n) && i < 8)
	{
		std::cout << "|";
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << strunc(this->_contacts[i].first_name, 10) << "|";
		std::cout << std::setw(10) << strunc(this->_contacts[i].last_name, 10) << "|";
		std::cout << std::setw(10) << strunc(this->_contacts[i].nick_name, 10) << "|\n";
		std::cout << std::string(45, '-') << std::endl;
		i++;
	}
	tmp = prompt("index: ");
	if (tmp.size() == 1 && tmp.c_str()[0] >= '0' && tmp.c_str()[0] <= '7' && tmp.c_str()[1] == '\0')
		PhoneBook::getContact(tmp.c_str()[0] - '0');
	else
		std::cerr << "error: bad index\n";
	return ;
}

static std::string	strunc(std::string str, size_t size)
{
	std::string	tmp;

	tmp = str.substr(0, size + 1);
	if (tmp.length() > size)
		tmp = tmp.replace(size - 1, 2, ".");
	return (tmp);
}

static std::string	prompt(std::string str)
{
	std::string	tmp;
	
	std::cout << str;
	std::getline(std::cin, tmp);
	if (std::cin.eof() || std::cin.fail())
		exit (0);
	return (tmp);
}
