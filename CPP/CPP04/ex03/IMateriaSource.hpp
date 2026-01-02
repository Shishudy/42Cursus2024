/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 17:42:27 by rafasant          #+#    #+#             */
/*   Updated: 2026/01/02 17:43:26 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

class IMateriaSource
{
	public:
		IMateriaSource(void);
		IMateriaSource(const IMateriaSource &);
		IMateriaSource &operator=(const IMateriaSource &);
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
		virtual ~IMateriaSource(void);
	private:
	
};

#endif