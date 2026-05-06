/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 18:04:36 by rafasant          #+#    #+#             */
/*   Updated: 2026/05/06 20:45:45 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
# include <string>
# include <cstdlib>
# include <errno.h>

class ScalarConverter
{
	public:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &);
		ScalarConverter &operator=(const ScalarConverter &);
		static void convert(std::string str);
		static bool IsChar(std::string str);
		static bool IsInt(const char *str, int *value);
		static bool IsDouble(const char *str, double *value);
		static bool IsFloat(const char *str, float *value);
		virtual ~ScalarConverter(void) = 0;
};

#endif