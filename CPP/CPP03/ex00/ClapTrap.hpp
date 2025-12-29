/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:53:37 by rafasant          #+#    #+#             */
/*   Updated: 2025/12/29 17:23:31 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

class ClapTrap
{
	public:
		ClapTrap(std::string);
		ClapTrap(const ClapTrap &);
		ClapTrap &operator=(const ClapTrap &);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void showHitPoints(void);
		void showEnergy(void);
		void showAttackDamage(void);
		~ClapTrap(void);
	private:
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
		std::string _name;
};

#endif