/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 09:58:35 by rafasant          #+#    #+#             */
/*   Updated: 2026/01/07 18:28:05 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>
# include <string>

class Weapon
{
	public:
		Weapon(std::string);
		void setType(std::string);
		const std::string &getType(void) const;
		~Weapon(void);

	private:
		std::string	type;
};

#endif