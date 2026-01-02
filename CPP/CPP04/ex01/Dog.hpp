/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 20:38:56 by rafasant          #+#    #+#             */
/*   Updated: 2026/01/02 16:23:27 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog(void);
		Dog(const Dog &);
		Dog &operator=(const Dog &);
		void makeSound(void) const;
		std::string getIdea(int index) const;
		void setIdea(int index, const std::string &idea);
		~Dog(void);
	private:
		Brain *_brain;
};

#endif