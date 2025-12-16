/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 20:52:13 by rafasant          #+#    #+#             */
/*   Updated: 2025/12/16 18:40:49 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H
# include <iostream>

class Zombie
{
	public:
		Zombie();
		Zombie(std::string name);
		void announce(void);
		void SetName(std::string name);
		~Zombie(void);

	private:
		std::string	name;
};

Zombie	*zombieHorde(int N, std::string name);

#endif