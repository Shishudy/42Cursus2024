/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 20:52:16 by rafasant          #+#    #+#             */
/*   Updated: 2025/12/16 19:03:22 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

	std::cout << "The memory address of the string variable: "<< &str << std::endl;
	std::cout << "The memory address held by stringPTR: "<< stringPTR << std::endl;
	std::cout << "The memory address held by stringREF: "<< &stringREF << std::endl;
    
    std::cout << "The value of the string variable: "<< str << std::endl;
	std::cout << "The value pointed to by stringPTR: "<< *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF: "<< stringREF << std::endl;
}