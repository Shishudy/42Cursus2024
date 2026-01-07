/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 13:36:14 by rafasant          #+#    #+#             */
/*   Updated: 2026/01/07 18:43:03 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
# include <iostream>
# include <string>

class Harl
{
	public:
		Harl(void);
		void complain(std::string level);
		~Harl(void);
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
};

struct LevelsDictionary
{
	std::string	level;
	void (Harl::*function)(void);
};

#endif