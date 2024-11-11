/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:43:24 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/11 14:29:24 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// Constructor
PhoneBook::PhoneBook()
{
	num_entries = 0;
}

// Destructor
PhoneBook::~PhoneBook()
{
	
}

void	PhoneBook::add_contact(std::string fname, std::string lname, std::string nname,
				 std::string phone, std::string secret)
{
		contacts[num_entries] = Contact(fname, lname, nname, phone, secret);
		num_entries = (num_entries + 1) % MAX_CONTACT;
}

Contact	PhoneBook::get_contact(int index)
{
	return (contacts[index]);
}

bool	PhoneBook::is_valid(int index)
{
	if (PhoneBook::contacts[index].getFirstName().empty())
		return false;
	else
		return true;
}

void	PhoneBook::display_contact_info(int index)
{
	std::cout << "First Name : ";
	std::cout << PhoneBook::contacts[index].getFirstName() << "\n";
	std::cout << "Last Name : ";
	std::cout << PhoneBook::contacts[index].getLastName() << "\n";
	std::cout << "Nickname : ";
	std::cout << PhoneBook::contacts[index].getNickName() << "\n";
	std::cout << "Phone Number : ";
	std::cout << PhoneBook::contacts[index].getPhoneNumber() << "\n";
	std::cout << "Darkest Secret : ";
	std::cout << PhoneBook::contacts[index].getDarkSecret() << "\n\n";
}
