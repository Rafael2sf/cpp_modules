/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:23:22 by rafernan          #+#    #+#             */
/*   Updated: 2022/05/06 12:26:18 by rafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include "Contact.hpp"

class PhoneBook 
{
	public:
		PhoneBook(void);
		~PhoneBook();

		void	setContact(void);
		void	getContact(int index) const;
		void	search(void) const;
	private:
		Contact	_contacts[8];
		int		_n;
};

#endif /* PHONEBOOK_HPP */