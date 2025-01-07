/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:09:25 by thomas            #+#    #+#             */
/*   Updated: 2025/01/07 18:23:26 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>
# include <iostream>
# include <fstream>

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

		int	read_data_base(void);
};

#endif