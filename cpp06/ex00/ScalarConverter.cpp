/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 12:20:13 by thomas            #+#    #+#             */
/*   Updated: 2024/12/10 11:22:48 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// Delete copy assignment operator
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

// Static method for conversion
void ScalarConverter::convert(const std::string& input)
{
	if (is_char(input))
		display_from_char(input);
	else if (is_int(input))
		display_from_int(input);
	else if (is_float(input))
		display_from_float(input);
	else if (is_double(input))
		display_from_double(input);
	else
		std::cout << "No valid types\n";
}