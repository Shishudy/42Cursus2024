/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 18:05:57 by rafasant          #+#    #+#             */
/*   Updated: 2026/05/06 20:49:48 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &ScalarConverter)
{
	std::cout << "ScalarConverter copy constructor called" << std::endl;
	*this = ScalarConverter;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &ScalarConverter)
{
	std::cout << "ScalarConverter copy assignment operator called" << std::endl;
	if (this != &ScalarConverter)
	{
	}
	return *this;
}

void ScalarConverter::convert(std::string str)
{
	int i_value;
	double d_value;
	float f_value;

	const char	*c_str = str.c_str();
	if (IsInt(c_str, &i_value))
		std::cout << "It is int " << i_value << std::endl;
	else if (IsDouble(c_str, &d_value))
		std::cout << "It is double " << d_value << std::endl;
	else if (IsFloat(c_str, &f_value))
		std::cout << "It is float " << f_value << std::endl;
	else
		std::cout << "It is none" << std::endl;
}

bool ScalarConverter::IsChar(std::string str)
{
	(void)str;
	return true;
}

bool ScalarConverter::IsInt(const char *str, int *value)
{
	char	*end;
	errno = 0;

	*value = strtol(str, &end, 10);
	if (errno || (value == 0 && str == end) || *end != '\0')
	{
		return (false);
	}
	return (true);
}

bool ScalarConverter::IsDouble(const char *str, double *value)
{
	char	*end;
	errno = 0;

	*value = strtod(str, &end);
	if (errno || (value == 0 && str == end) || *end != '\0')
	{
		return (false);
	}
	return (true);
}

bool ScalarConverter::IsFloat(const char *str, float *value)
{
	char	*end;
	errno = 0;

	*value = strtof(str, &end);
	if (errno || (value == 0 && str == end) || *end != '\0')
	{
		return (false);
	}
	return (true);
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "ScalarConverter destructor called" << std::endl;
}