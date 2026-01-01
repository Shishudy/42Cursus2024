/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 17:28:09 by rafasant          #+#    #+#             */
/*   Updated: 2026/01/01 18:11:49 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap(std::string);
		DiamondTrap(const DiamondTrap &);
		DiamondTrap &operator=(const DiamondTrap &);
		void attack(const std::string& target);
		void whoAmI(void);
		~DiamondTrap(void);
	private:
		std::string _name;
};

#endif