/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:37:38 by thomas            #+#    #+#             */
/*   Updated: 2024/11/08 18:02:54 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "main.hpp"
#include <cstdlib>

int	main()
{
	std::string command;
	PhoneBook phonebook;
	std::cout << "Welcome to My Awesome PhoneBook.\n";
	while (1)
	{
		std::cout << "Enter ADD to save a new contact.\n";
		std::cout << "Enter SEARCH to search for a contact.\n";
		std::cout << "Enter EXIT to leave the program\n";
		std::cout << "Enter command : ";
		std::getline(std::cin, command);
		if (command == "ADD")
			new_contact();
		else if (command == "SEARCH")
			search_contact();
		else if (command == "EXIT")
			exit(0);
	}
	return (0);
}
