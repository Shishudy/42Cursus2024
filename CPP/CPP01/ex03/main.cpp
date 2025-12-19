/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 09:53:38 by rafasant          #+#    #+#             */
/*   Updated: 2025/12/19 13:12:24 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return (0);
}

// int main()
// {
// 	Weapon club = Weapon("crude spiked club");
// 	HumanA bob("Bob", club);
// 	bob.attack();
// 	club.setType("some other type of club");
// 	bob.attack();
// 	club.setType("crude spiked club");
// 	bob.attack();
// 	HumanB jim("Jim");
// 	jim.setWeapon(club);
// 	jim.attack();
// 	club.setType("some other type of club");
// 	jim.attack();
// 	bob.attack();
// 	return (0);
// }