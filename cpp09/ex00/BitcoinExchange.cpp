/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:09:51 by thomas            #+#    #+#             */
/*   Updated: 2025/01/07 18:44:29 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//Constructors
BitcoinExchange::BitcoinExchange(): map_data() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other): map_data(other.map_data) {}

//Copy Assignment Operator
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) 
{
	if (this != &other)
	{
		map_data = other.map_data;
	}
	return (*this);
}

//Destructor
BitcoinExchange::~BitcoinExchange() {}

//Method
int	BitcoinExchange::print_exchange_rate_from_input(std::string input_file)
{
	if (BitcoinExchange::read_data_base()) {
		std::cout << "Error: could not open file.\n";
		return 0; //value return by main later to indicate failure...
	}
}

int	BitcoinExchange::read_data_base()
{
	std::ifstream inputfile("data.csv");
	if (!inputfile.is_open())
		return (1);
	
	std::string line;
	std::getline(inputfile, line);
	while (std::getline(inputfile, line))
	{
		std::size_t found = line.find(',');
		std::string date = line.substr(0, found);
		std::string rate = line.substr(found + 1);
	}
}

