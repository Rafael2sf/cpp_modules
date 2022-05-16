/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:07:49 by rafernan          #+#    #+#             */
/*   Updated: 2022/05/16 22:45:10 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

static int	containsAlpha(std::string ref);

Contact::Contact(void):first_name(""), last_name(""), nick_name(""), number(""), dark_secret("")
{}

Contact::~Contact()
{}

int	Contact::isValidContact(void) const
{
	if (containsAlpha(this->first_name)
		&& containsAlpha(this->last_name)
		&& containsAlpha(this->nick_name)
		&& containsAlpha(this->number)
		&& containsAlpha(this->dark_secret))
	{
		return (1);
	}
	return (0);
}

static int	containsAlpha(std::string ref)
{
	int	i = 0;
	int	lenght;

	lenght = ref.length();
	while (i < lenght)
	{
		if (isgraph(ref[i++]))
			return (1);
	}
	return (0);
}
