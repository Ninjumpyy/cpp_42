/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:48:50 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/08 17:23:47 by tle-moel         ###   ########.fr       */
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