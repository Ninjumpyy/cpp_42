/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:43:42 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/08 17:23:45 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define MAX_CONTACT 8

class PhoneBook
{
	private:
		Contact contacts[MAX_CONTACT];
		int		num_entries;

	public:
		//Constructor
		PhoneBook();

		//Destructor
		~PhoneBook();

		void	add_contact(std::string fname, std::string lname, std::string nname,
				 std::string phone, std::string secret);
};

#endif