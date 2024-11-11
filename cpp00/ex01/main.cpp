/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:37:38 by thomas            #+#    #+#             */
/*   Updated: 2024/11/11 14:39:54 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	main()
{
	std::string command;
	PhoneBook 	phonebook;
	
	std::cout << "Welcome to My Awesome PhoneBook.\n";
	while (1)
	{
		std::cout << "Enter ADD to save a new contact. Enter SEARCH to search for a contact. Enter EXIT to leave the program\n\n";
		std::cout << "Enter command : ";
		std::getline(std::cin, command);
		if (command == "ADD")
			new_contact(phonebook);
		else if (command == "SEARCH")
			search_contact(phonebook);
		else if (command == "EXIT")
			exit(0);
	}
	return (0);
}
