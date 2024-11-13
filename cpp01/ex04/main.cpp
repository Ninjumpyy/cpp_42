/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:08:52 by thomas            #+#    #+#             */
/*   Updated: 2024/11/13 18:09:13 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int	main(int argc, char **argv)
{	
	if (argc != 4)
	{
		std::cerr << "Usage: ./sed filename string1 string2\n";
		return (1);
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::string new_file = filename + ".replace";

	std::ifstream inputfile(filename.c_str());
	if (!inputfile.is_open())
	{
		std::cerr << "Error: Could not open the input file.\n";
		return (1);
	}
	std::ofstream outputfile(new_file.c_str());
	if (!outputfile.is_open())
	{
		std::cerr << "Error: Could not open the output file.\n";
		inputfile.close();
		return (1);
	}

	std::string line;
	std::size_t	start;
	std::size_t	end;
	while (std::getline(inputfile, line))
	{
		start = 0;
		end = line.find(s1);
		while (end != std::string::npos)
		{
			outputfile << line.substr(start, (end - start)) << s2;
			start = end + s1.length();
			end = line.find(s1, start);
		}
		outputfile << line.substr(start, line.length()) << std::endl;
	}
	
	inputfile.close();
	outputfile.close();
	return (0);
}
