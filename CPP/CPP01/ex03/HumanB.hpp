/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 09:58:33 by rafasant          #+#    #+#             */
/*   Updated: 2025/12/17 12:07:53 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string);
		void setWeapon(Weapon &);
		void attack(void);
		~HumanB(void);
		
	private:
		std::string	name;
		Weapon		*weapon;
};

#endif