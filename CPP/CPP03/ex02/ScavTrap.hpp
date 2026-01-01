/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 15:42:45 by rafasant          #+#    #+#             */
/*   Updated: 2026/01/01 16:24:37 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(std::string);
		ScavTrap(const ScavTrap &);
		ScavTrap &operator=(const ScavTrap &);
		void attack(const std::string& target);
		void guardGate(void);
		~ScavTrap(void);
	private:
};

#endif