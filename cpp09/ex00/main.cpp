/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:09:10 by thomas            #+#    #+#             */
/*   Updated: 2025/01/07 17:51:56 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "Usage: ./btc [input_file]\n";
		return (1);
	}

	BitcoinExchange object;
	return object.print_exchange_rate_from_input(argv[1]);
	
}

