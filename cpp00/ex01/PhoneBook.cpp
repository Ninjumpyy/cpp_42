/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:43:24 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/08 17:23:46 by tle-moel         ###   ########.fr       */
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
