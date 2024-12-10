/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 12:20:24 by thomas            #+#    #+#             */
/*   Updated: 2024/12/09 16:15:02 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include "helper.hpp"

class ScalarConverter
{
	private:
		// Private constructor and destructor to prevent instantiation
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);

		// Delete copy assignment operator
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();

	public:
		// Static method for conversion
		static void convert(const std::string& input);
};

#endif