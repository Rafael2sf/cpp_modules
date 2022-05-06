/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:40:48 by rafernan          #+#    #+#             */
/*   Updated: 2022/05/05 15:27:25 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	public:
		Contact();
		~Contact();
		
		int	isValidContact(void) const;
		std::string	first_name;
		std::string	last_name;
		std::string	nick_name;
		std::string	number;
		std::string	dark_secret;
};

#endif /* CONTACT_HPP */