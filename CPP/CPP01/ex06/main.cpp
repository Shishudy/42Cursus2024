/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:59:53 by rafasant          #+#    #+#             */
/*   Updated: 2025/12/19 15:40:54 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl harl;
	
	if (argc != 2)
	{
		std::cerr << "Invalid number of parameters provided! Arguments required are: [level]" << std::endl;
		return (1);
	}
	harl.complain(argv[1]);
	return 0;
}