/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:09:51 by thomas            #+#    #+#             */
/*   Updated: 2025/01/09 15:33:29 by thomas           ###   ########.fr       */
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
	if (!BitcoinExchange::read_data_base())
		return 1; //Indicate failure...
	
	std::ifstream inputfile(input_file.c_str());
	if (!inputfile.is_open()) {
		std::cerr << "Error: could not open input file.\n";
		return 1;
	}

	std::string line;
	if (std::getline(inputfile, line) && line != "date | value")
		BitcoinExchange::process_line(line);
	while (std::getline(inputfile, line))
	{
		BitcoinExchange::process_line(line);
	}
	inputfile.close();
	return 0; //Indicate success...
}

void	BitcoinExchange::process_line(std::string line)
{
	if (!BitcoinExchange::valid_delim(" | ", line)) {
			std::cerr << "Error: bad input => " << line << std::endl;
			return;
		}
		std::size_t found = line.find(" | ");
		std::string date = line.substr(0, found);
		if (!BitcoinExchange::valid_date_format(date)) {
			std::cerr << "Error: date => " << date << std::endl;
			return;
		}
		std::string value_str = line.substr(found + 3);
		double value = atof(value_str.c_str());
		if (value < 0) {
			std::cerr << "Error: not a positive number.\n";
			return;
		}
		else if (value > 1000) {
			std::cerr << "Error: too large number.\n";
			return;
		}
		BitcoinExchange::print_result(date, value);
}

bool	BitcoinExchange::read_data_base()
{
	std::ifstream inputfile("data.csv");
	if (!inputfile.is_open()) {
		std::cerr << "Error: could not open data base.\n";
		return false;
	}
	
	std::string line;
	std::getline(inputfile, line);
	while (std::getline(inputfile, line))
	{
		if (!BitcoinExchange::valid_delim(",", line)) {
			std::cerr << "Error: format data base.\n";
			return false;
		}
		std::size_t found = line.find(',');
		std::string date = line.substr(0, found);
		if (!BitcoinExchange::valid_date_format(date)) {
			std::cerr << "Error: format data base.\n";
			return false;
		}
		std::string rate_str = line.substr(found + 1);
		double rate = atof(rate_str.c_str());
		if (!BitcoinExchange::valid_exchange_rate(rate)) {
			std::cerr << "Error: format data base.\n";
			return false;
		}
		map_data.insert(std::pair<std::string, double>(date, rate));
	}
	inputfile.close();
	return true;
}

bool BitcoinExchange::valid_exchange_rate(double value)
{
	if (value < 0 || value > std::numeric_limits<float>::max())
		return false;
	return true;
}

bool BitcoinExchange::valid_value(double value)
{
	if (value < 0 || value > 1000)
		return false;
	return true;
}

bool BitcoinExchange::valid_delim(std::string delim, std::string line)
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

bool BitcoinExchange::valid_date_format(std::string date)
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

	std::tm time_struct = {};
	time_struct.tm_year = atoi(year.c_str()) - 1900;
	time_struct.tm_mon = atoi(month.c_str()) - 1;
	time_struct.tm_mday = atoi(day.c_str());
	std::tm normalized_date = time_struct;
	mktime(&normalized_date);
	if (time_struct.tm_year != normalized_date.tm_year ||
		time_struct.tm_mon != normalized_date.tm_mon ||
		time_struct.tm_mday != normalized_date.tm_mday)
		return false;
	
	return true;
}

void BitcoinExchange::print_result(std::string date, double value)
{
	std::map<std::string, double>::iterator it;

	it = map_data.lower_bound(date);
	if (it == map_data.begin() && it->first != date)
		std::cerr << "Error: no valid date in DB for " << date << std::endl;
	else if (it == map_data.end()) {
		it--;
		std::cout << date << " => " << value << " = " << (it->second * value) << std::endl;
	}
	else if (it->first > date) {
		it--;
		std::cout << date << " => " << value << " = " << (it->second * value) << std::endl;
	}
	else
		std::cout << date << " => " << value << " = " << (it->second * value) << std::endl;
	return ;
}
