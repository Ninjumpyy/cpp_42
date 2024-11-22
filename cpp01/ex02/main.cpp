/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:01:21 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/22 16:06:51 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "The memory address of the string variable : "
			  << &str << "\n";
	std::cout << "The memory address held by stringPTR : "
			  << &stringPTR << "\n";
	std::cout << "The memory address held by stringREF : "
			  << &stringREF << "\n";
	std::cout << std::endl;
	std::cout << "Value of str : " << str << std::endl;
	std::cout << "Value pointed to by stringPTR : "
			  << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF : "
			  << stringREF << std::endl;

	return (0);
}