/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:09:51 by thomas            #+#    #+#             */
/*   Updated: 2025/01/08 17:12:42 by thomas           ###   ########.fr       */
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
	if (!BitcoinExchange::read_data_base()) {
		std::cout << "Error: could not open file.\n";
		return 0; //value return by main later to indicate failure...
	}
}

bool	BitcoinExchange::read_data_base()
{
	std::ifstream inputfile("data.csv");
	if (!inputfile.is_open())
		return false;
	
	std::string line;
	std::getline(inputfile, line);
	while (std::getline(inputfile, line))
	{
		std::size_t found = line.find(',');
		std::string date = line.substr(0, found);
		std::string rate_str = line.substr(found + 1);
		double rate = stod(rate_str);
		map_data.insert({date, rate});
	}
	return true;
}

bool BitcoinExchange::handle_float(double value)
{
	if (value < 0 || value >  std::numeric_limits<float>::max())
		return false;
	return true;
}

bool BitcoinExchange::handle_delim(char delim, std::string line)
{
	std::size_t found = line.find(delim);
	if (found != std::string::npos)
	{
		found = line.find(delim, found + 1);
		if (found == std::string::npos)
			return true;
	}
	return false;
}

bool BitcoinExchange::handle_date_format(std::string date)
{
	std::size_t first_hyphen = date.find('-');
	std::size_t second_hyphen = date.find_last_of('-');

	std::string year = date.substr(0, first_hyphen);
	std::string month = date.substr(first_hyphen + 1, second_hyphen - first_hyphen - 1);
	std::string day = date.substr(second_hyphen + 1);

	if (year.length() != 4 || month.length() != 2 || day.length() != 2)
		return false;
	if (year.find_first_not_of("0123456789") != std::string::npos ||
		month.find_first_not_of("0123456789") != std::string::npos || 
		day.find_first_not_of("0123456789") != std::string::npos)
		return false;

	




	std::string year = date.substr(0, first_hyphen);
	if (year.find_first_not_of("0123456789") != std::string::npos)
		return false;
	std::string month = date.substr(first_hyphen + 1, second_hyphen - first_hyphen - 1);
	if (month.length() != 2 && atoi(month.c_str()) > 12)
		return false;
	std::string day = date.substr(second_hyphen + 1);
	if (day.length() != 2 || atoi(day.c_str()) > 31)
}
