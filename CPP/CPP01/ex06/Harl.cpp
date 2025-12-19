/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 13:36:18 by rafasant          #+#    #+#             */
/*   Updated: 2025/12/19 15:46:58 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{

}

void Harl::complain(std::string level)
{
	const LevelsDictionary	dict[4] = {{"DEBUG", &Harl::debug}, {"INFO", &Harl::info}, {"WARNING", &Harl::warning}, {"ERROR", &Harl::error}};
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!dict[i].level.compare(level))
		{
			std::cout << "[ " << dict[i].level << " ]" << std::endl;
			break ;
		}
		i++;
	}
	switch(i)
	{
		case (0):
			(this->*dict[0].function)();
			// fall through
		case (1):
			(this->*dict[1].function)();
			// fall through
		case (2):
			(this->*dict[2].function)();
			// fall through
		case (3):
			(this->*dict[3].function)();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

void Harl::debug(void)
{
	std::cout << "Who even needs gdb" << std::endl;
}

void Harl::info(void)
{
	std::cout << "Such info, much wow" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "This is fine *sips coffee*" << std::endl;
}

void Harl::error(void)
{
	std::cout << "Oh my god, okay, it's happening! Everybody stay calm, everybody stay calm! STAY F*****G CALM!" << std::endl;
}

Harl::~Harl(void)
{
	
}