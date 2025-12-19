/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:17:19 by rafasant          #+#    #+#             */
/*   Updated: 2025/12/19 13:31:16 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <fstream>

int	main(int argc, char **argv)
{
	std::string	fileName;
	std::string	s1;
	std::string	s2;
	std::string	buffer;
	std::string result;
	std::size_t pos;
	std::size_t found;

	if (argc != 4)
	{
		std::cerr << "Invalid number of parameters provided! Arguments required are: [file] [string to replace] [string to replace with]" << std::endl;
		return (1);
	}
	fileName = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	if (s1.empty())
	{
		std::cerr << "Invalid [string to replace] provided!" << std::endl;
		return (1);
	}
	std::ifstream inFile(fileName.c_str());
	if (inFile.is_open() == false)
	{
		std::cerr << "Failed opening " << fileName << "!" << std::endl;
		return (1);
	}
	std::ofstream outFile((fileName + ".replace").c_str());
	if (outFile.is_open() == false)
	{
		inFile.close();
		std::cerr << "Failed opening " << fileName << ".replace" << "!" << std::endl;
		return (1);
	}
	while (std::getline(inFile, buffer))
	{
		pos = 0;
		result.clear();
		while (1)
		{
			found = buffer.find(s1, pos);
			if (found == std::string::npos)
				break ;
			result += buffer.substr(pos, found - pos);
			result += s2;
			pos = found + s1.length();
		}
		result += buffer.substr(pos);
		if (!inFile.eof())
		{
			result += '\n';
		}
		outFile << result;
	}
	inFile.close();
	outFile.close();
	return (0);
}