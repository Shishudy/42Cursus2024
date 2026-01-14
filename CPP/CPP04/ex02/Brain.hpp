/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 12:15:39 by rafasant          #+#    #+#             */
/*   Updated: 2026/01/14 15:04:22 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>
# include <string>

class Brain
{
	public:
		Brain(void);
		Brain(const Brain &);
		Brain &operator=(const Brain &);
		std::string getIdea(int) const;
		void setIdea(int, const std::string &);
		~Brain(void);
	private:
		std::string _ideas[100];
};

#endif