/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 20:38:59 by rafasant          #+#    #+#             */
/*   Updated: 2026/01/02 16:23:22 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat(void);
		Cat(const Cat &);
		Cat &operator=(const Cat &);
		void makeSound(void) const;
		std::string getIdea(int index) const;
		void setIdea(int index, const std::string &idea);
		~Cat(void);
	private:
		Brain *_brain;
};

#endif