/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 17:01:45 by rafasant          #+#    #+#             */
/*   Updated: 2025/11/22 17:43:38 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook(void);
		void AddContact(void);
		void DisplayContacts(void);
		void DisplayContact();
		~PhoneBook(void);

	private:
		int		_count;
		Contact _contacts[8];
		void	_PrintField(std::string field);
		// Contact	*_nextContact;
};

#endif