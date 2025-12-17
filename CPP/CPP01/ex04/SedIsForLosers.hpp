/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedIsForLosers.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:19:46 by rafasant          #+#    #+#             */
/*   Updated: 2025/12/17 12:42:10 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_IS_FOR_LOSERS_HPP
# define SED_IS_FOR_LOSERS_HPP
# include <iostream>
# include <fstream>

class SedIsForLosers
{
	public:
		SedIsForLosers(std::string filename, std::string s1, std::string s2);
		~SedIsForLosers(void);

	private:
		std::string	_filename;
		std::string	_s1;
		std::string	_s2;
};

#endif