/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 17:16:52 by rafasant          #+#    #+#             */
/*   Updated: 2026/01/02 17:32:08 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class Character : ICharacter
{
	public:
		Character(void);
		Character(const Character &other);
		Character &operator=(const Character &other);
		virtual ~Character(void);
	private:
		
};

#endif