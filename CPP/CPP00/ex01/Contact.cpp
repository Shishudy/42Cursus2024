/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 17:40:11 by rafasant          #+#    #+#             */
/*   Updated: 2025/11/10 01:05:26 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	// this->_firstName.clear();
	// this->_lastName.clear();
	// this->_nickname.clear();
	// this->_phoneNumber.clear();
	// this->_darkestSecret.clear();
}

void Contact::CreateContact(void)
{
	while (this->_firstName.empty())
	{
		std::cout << "Enter the contact's first name: ";
		std::cin >> this->_firstName;
	}
	while (this->_lastName.empty())
	{
		std::cout << "Enter the contact's last name: ";
		std::cin >> this->_lastName;
	}
	while (this->_nickname.empty())
	{
		std::cout << "Enter a nickname for the contact: ";
		std::cin >> this->_nickname;
	}
	while (this->_phoneNumber.empty())
	{
		std::cout << "Enter the contact's phone number: ";
		std::cin >> this->_phoneNumber;
	}
	while (this->_darkestSecret.empty())
	{
		std::cout << "Enter the contact's darkest secret: ";
		std::cin >> this->_darkestSecret;
	}
}

std::string Contact::GetFirstName(void)
{
	return (this->_firstName);
}

std::string Contact::GetLastName(void)
{
	return (this->_lastName);
}

std::string Contact::GetNickname(void)
{
	return (this->_nickname);
}

std::string Contact::GetPhoneNumber(void)
{
	return (this->_phoneNumber);
}

std::string Contact::GetDarkestSecret(void)
{
	return (this->_darkestSecret);
}

Contact::~Contact(void)
{
	
}