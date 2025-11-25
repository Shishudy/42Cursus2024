/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 17:37:24 by rafasant          #+#    #+#             */
/*   Updated: 2025/11/22 18:49:54 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	int			index;
	std::string	input;
	PhoneBook 	Ph;

	std::cout << "Welcome to your Awesome (but very antiquated) PhoneBook!\nHere you can register up to 8 contacts and visualize them!" << std::endl;
	std::cout << "Insert ADD to register a new contact, SEARCH to visualize your contact list or EXIT to exit the menu." << std::endl;
	std::cin >> input;
	while (input.compare("EXIT") != 0)
	{
		if (input.compare("ADD") == 0)
		{
			Ph.AddContact();
		}
		else if (input.compare("SEARCH") == 0)
		{
			Ph.DisplayContacts();
			input.clear();
			std::cin >> input;
			index = atoi(input);
			if (index == 0)
		}
		input.clear();
		std::cin >> input;
	}
	return (0);
}