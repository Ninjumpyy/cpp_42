/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:09:25 by thomas            #+#    #+#             */
/*   Updated: 2025/01/08 17:12:43 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>
# include <string.h>
# include <iostream>
# include <fstream>
# include <limits>
# include <stdlib.h>

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

		bool	read_data_base(void);
		bool handle_float(double value);
		bool handle_delim(char delim, std::string line);
		bool handle_date_format(std::string date);
};

#endif