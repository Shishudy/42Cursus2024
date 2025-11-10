/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 17:40:29 by rafasant          #+#    #+#             */
/*   Updated: 2025/11/10 00:59:28 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H
#include <iostream>
#include <string>

class Contact
{
	public:
		Contact(void);
		void CreateContact(void);
		std::string GetFirstName(void);
		std::string GetLastName(void);
		std::string GetNickname(void);
		std::string GetPhoneNumber(void);
		std::string GetDarkestSecret(void);
		~Contact(void);

	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
};

#endif