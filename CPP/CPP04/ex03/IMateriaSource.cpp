/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:17:46 by rafasant          #+#    #+#             */
/*   Updated: 2026/01/02 18:17:49 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <iostream>
# include <string>

class IMateriaSource
{
	public:
		IMateriaSource(void);
		IMateriaSource(const IMateriaSource &);
		IMateriaSource &operator=(const IMateriaSource &);
		virtual ~IMateriaSource(void);
	private:
		
};

#endif