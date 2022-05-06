/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:07:49 by rafernan          #+#    #+#             */
/*   Updated: 2022/05/06 12:26:04 by rafernan         ###   ########.fr       */
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
	int	i;

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
