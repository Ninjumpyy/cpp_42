/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:09:25 by thomas            #+#    #+#             */
/*   Updated: 2025/01/09 11:43:59 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>
# include <iostream>
# include <fstream>
# include <limits>
# include <stdlib.h>
# include <ctime>
# include <cstdlib>

class BitcoinExchange
{
	public:
		//Constructors
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);

		//Copy Assignment Operator
		BitcoinExchange& operator=(const BitcoinExchange& other);

		//Destructor
		~BitcoinExchange();

		//Method
		int print_exchange_rate_from_input(std::string input_file);
	
	private:
		std::map<std::string, double> map_data;

		bool read_data_base(void);
		bool valid_exchange_rate(double value);
		bool valid_value(double value);
		bool valid_delim(std::string delim, std::string line);
		bool valid_date_format(std::string date);
		void print_result(std::string date, double value);
		void process_line(std::string line);
};

#endif