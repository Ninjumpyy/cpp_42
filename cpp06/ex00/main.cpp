/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 12:20:10 by thomas            #+#    #+#             */
/*   Updated: 2025/01/10 13:28:19 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <string>
#include <iostream>

int main(int argc, char **argv) 
{
	if (argc != 2)
	{
		std::cout << "Usage: ./converter argument" << std::endl;
		return 1;
	}
	std::string argument = argv[1];
	ScalarConverter::convert(argument);
    return 0;
}
