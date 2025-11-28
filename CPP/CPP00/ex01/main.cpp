/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 17:37:24 by rafasant          #+#    #+#             */
/*   Updated: 2025/11/28 20:26:06 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	int			index;
	std::string	input;
	PhoneBook 	Ph;

	std::cout << "Welcome to your Awesome (but very antiquated) PhoneBook!\nHere you can register up to 8 contacts and visualize them!" << std::endl;
	input = "";
	while (1)
	{
		std::cout << "Insert ADD to register a new contact, SEARCH to visualize your contact list or EXIT to exit the menu." << std::endl;
		input.clear();
		std::cin >> input;
		if (input.compare("ADD") == 0)
		{
			Ph.AddContact();
		}
		else if (input.compare("SEARCH") == 0)
		{
			Ph.DisplayContacts();
			if (Ph.GetNumberOfContacts() == 0)
				std::cout << "No contacts to list. Try adding some!\n";
			else
			{
				std::cout << "Press 0 to continue or select a contact: ";
				while (1)
				{
					input.clear();
					std::cin >> input;
					index = atoi(input.c_str());
					if (index == 0)
						break ;
					if (index >= 1 && index <= 8 && index <= Ph.GetNumberOfContacts())
					{
						Ph.DisplayContact(index - 1);
						break;
					}
					else
						std::cout << "Please select a contact, from 1 to " << Ph.GetNumberOfContacts() << ", or 0 to leave: ";
				}
			}
		}
		else if (input.compare("EXIT") == 0)
			break ;
		std::cout << std::endl;
	}
	return (0);
}