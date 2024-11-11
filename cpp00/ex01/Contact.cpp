/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:48:50 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/11 13:21:38 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// Constructor
Contact::Contact()
{
	first_name = "";
	last_name = "";
	nickname = "";
	phone_number = "";
	darkest_secret = "";
}
Contact::Contact(std::string fname, std::string lname, std::string nname,
				 std::string phone, std::string secret)
	: first_name(fname), last_name(lname), nickname(nname), phone_number(phone), darkest_secret(secret)
	{
		
	}

// Destructor
Contact::~Contact()
{
	
}

std::string	Contact::getFirstName(void) const
{
	return first_name;
}

std::string	Contact::getLastName(void) const
{
	return last_name;
}

std::string	Contact::getNickName(void) const
{
	return nickname;
}

std::string	Contact::getPhoneNumber(void) const
{
	return phone_number;
}

std::string	Contact::getDarkSecret(void) const
{
	return darkest_secret;
}