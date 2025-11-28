/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 17:01:40 by rafasant          #+#    #+#             */
/*   Updated: 2025/11/28 20:29:52 by rafasant         ###   ########.fr       */
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

	if (position >= 8)
		position = 0;
	this->_contacts[position].CreateContact();
	position++;
	if (this->_count < 8)
		this->_count++;
	std::cout << "Contact has been successfully added!\n";
}

int PhoneBook::GetNumberOfContacts(void)
{
	return this->_count;
}

void PhoneBook::DisplayContacts(void)
{
	int			i;
	std::string	field;
	
	std::cout << "---------------------------------------------" << "\n";
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << "\n";
	i = 0;
	while (i < this->_count)
	{
		std::cout << "|";
		std::cout << "         " << i + 1;
		std::cout << "|";
		this->_PrintField(this->_contacts[i].GetFirstName(), false);
		std::cout << "|";
		this->_PrintField(this->_contacts[i].GetLastName(), false);
		std::cout << "|";
		this->_PrintField(this->_contacts[i].GetNickname(), false);
		std::cout << "|";
		std::cout << "\n";
		i++;
	}
	std::cout << "---------------------------------------------" << "\n";
}

void PhoneBook::DisplayContact(int i)
{
	std::cout << "First Name: ";
	this->_PrintField(this->_contacts[i].GetFirstName(), true);
	std::cout << "\n";
	std::cout << "Last Name: ";
	this->_PrintField(this->_contacts[i].GetLastName(), true);
	std::cout << "\n";
	std::cout << "Nickname: ";
	this->_PrintField(this->_contacts[i].GetNickname(), true);
	std::cout << "\n";
	std::cout << "Phone Number: ";
	this->_PrintField(this->_contacts[i].GetPhoneNumber(), true);
	std::cout << "\n";
	std::cout << "Darkest Secret: ";
	this->_PrintField(this->_contacts[i].GetDarkestSecret(), true);
	std::cout << "\n";
}

void PhoneBook::_PrintField(std::string field, bool verbose)
{
	int	spaces;

	if (verbose == true)
	{
		std::cout << field;
		return ;
	}
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
}