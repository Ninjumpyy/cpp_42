/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:40:17 by thomas            #+#    #+#             */
/*   Updated: 2024/12/10 12:22:51 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.hpp"

bool	is_char(const std::string& s)
{
	if (s.length() == 1 && isprint(s[0]) && !isdigit(s[0]))
		return true;
	return false;
}

bool	is_int(const std::string& s)
{
	char	*end;
	long int value = std::strtol(s.c_str(), &end, 10);

	if (end != s.c_str() && *end == '\0' && value <= std::numeric_limits<int>::max() && value >= std::numeric_limits<int>::min())
		return true;
	return false;
}

bool	is_float(const std::string& s)
{
	if (s == "-inff" || s == "+inff" || s == "nanf")
		return true;
	if (s.find('.') == std::string::npos)
		return false;

	char	*end;
	errno = 0;
	strtof(s.c_str(), &end);

	if (errno == ERANGE)
		return false;
	if (end != s.c_str() && *end == 'f' && *(end + 1) == '\0')
		return true;
	return false;
}

bool	is_double(const std::string& s)
{
	if (s == "-inf" || s == "+inf" || s == "nan")
		return true;
	if (s.find('.') == std::string::npos)
		return false;

	char	*end;
	errno = 0;
	strtod(s.c_str(), &end);

	if (errno == ERANGE)
		return false;
	if (end != s.c_str() && *end == '\0')
		return true;
	return false;
}

void	display_from_char(const std::string& s)
{
	char	c;

	c = s[0];
	
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<int>(c) << ".0" << std::endl;
}

void	display_from_int(const std::string& s)
{
	int i = strtol(s.c_str(), NULL, 10);

	if (i >= 32 && i <= 126)
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	else if (i >= 0 && i <= 31)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: Impossible" << std::endl;

	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" <<std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void	display_from_float(const std::string& s)
{
	float f = strtof(s.c_str(), NULL);

	if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min() || f != static_cast<float>(static_cast<int>(f)))
		std::cout << "char: Impossible" << std::endl;
	else if (f >= 32.0f && f <= 126.0f)
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
	else if (f >= 0.0f && f <= 31.0f)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: Impossible" << std::endl;

	if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min() || std::isnan(f))
		std::cout << "int: Impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;

	if (f == static_cast<float>(static_cast<int>(f)))
		std::cout << "float: " << f << ".0f" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;

	if (f == static_cast<float>(static_cast<int>(f)))
		std::cout << "double: " << static_cast<double>(f) << ".0" << std::endl;
	else
		std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void	display_from_double(const std::string& s)
{
	double d = strtod(s.c_str(), NULL);

	if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min() || d != static_cast<double>(static_cast<int>(d)))
		std::cout << "char: Impossible" << std::endl;
	else if (d >= 32.0 && d <= 126.0)
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	else if (d >= 0.0 && d <= 31.0)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: Impossible" << std::endl;

	if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min() || std::isnan(d))
		std::cout << "int: Impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;

	if (d > std::numeric_limits<float>::max() || d < std::numeric_limits<float>::min())
		std::cout << "float: Impossible" << std::endl;
	else if (d == static_cast<double>(static_cast<int>(d)))
		std::cout << "float: " << static_cast<float>(d) << ".0f" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;

	if (d == static_cast<double>(static_cast<int>(d)))
		std::cout << "double: " << d << ".0" << std::endl;
	else
		std::cout << "double: " << d << std::endl;
}