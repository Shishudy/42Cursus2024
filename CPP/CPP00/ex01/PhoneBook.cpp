/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 17:01:40 by rafasant          #+#    #+#             */
/*   Updated: 2025/11/10 01:14:42 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_count = 0;
}

PhoneBook::~PhoneBook(void)
{
	
}

void PhoneBook::AddContact(void)
{
	static int	position;

	this->_contacts[position].CreateContact();
	if (this->_count < 8)
		this->_count++;
	position++;
	if (position >= 8)
		position = 0;
	std::cout << "Contact has been successfully added!" << std::endl;
}

void PhoneBook::DisplayContacts(void)
{
	int			i;
	// int			index;
	std::string	field;

	std::cout << "|     Index|First Name| Last Name|  Nickname|" << "\n";
	i = 0;
	while (i < this->_count)
	{
		std::cout << "|";
		std::cout << "         " << i;
		std::cout << "|";
		this->_PrintField(this->_contacts[i].GetFirstName());
		this->_PrintField(this->_contacts[i].GetLastName());
		this->_PrintField(this->_contacts[i].GetNickname());
		std::cout << "\n";
		i++;
	}
	std::cout << std::endl;
}

void PhoneBook::_PrintField(std::string field)
{
	int	spaces;

	spaces = 10 - field.length();
	while (spaces > 0)
	{
		std::cout << " ";
		spaces--;
	}
	if (spaces < 0)
	{
		std::cout << field.substr(0, 9);
		std::cout << ".";
	}
	else
	{
		std::cout << field.substr(0, 10);
	}
	std::cout << "|";
}