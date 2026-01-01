/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:53:37 by rafasant          #+#    #+#             */
/*   Updated: 2026/01/01 21:47:17 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &);
		WrongAnimal &operator=(const WrongAnimal &);
		std::string getType(void) const;
		void makeSound(void) const;
		virtual ~WrongAnimal(void);
	protected:
		std::string _type;
};

#endif