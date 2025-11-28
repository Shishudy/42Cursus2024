/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 17:01:45 by rafasant          #+#    #+#             */
/*   Updated: 2025/11/28 20:31:21 by rafasant         ###   ########.fr       */
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
		void DisplayContact(int index);
		int	GetNumberOfContacts(void);
		~PhoneBook(void);

	private:
		int		_count;
		Contact _contacts[8];
		void	_PrintField(std::string field, bool verbose);
};

#endif