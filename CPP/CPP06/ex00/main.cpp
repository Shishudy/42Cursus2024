/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 18:21:20 by rafasant          #+#    #+#             */
/*   Updated: 2026/05/06 19:42:51 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
		std::cout << "Error: Input should consist of 1 parameter.";
	
	ScalarConverter::convert(argv[1]);

    return (0);
}