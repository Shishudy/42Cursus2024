/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 16:52:47 by rafasant          #+#    #+#             */
/*   Updated: 2026/01/01 19:36:25 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
	public:
		FragTrap(std::string);
		FragTrap(const FragTrap &);
		FragTrap &operator=(const FragTrap &);
		void highFivesGuys(void);
		~FragTrap(void);
		static const int defaultHitPoints = 100;
		static const int defaultEnergyPoints = 100;
		static const int defaultAttackDamage = 30;
	private:
};

#endif