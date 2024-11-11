/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:55:37 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/11 15:32:08 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void    new_contact(PhoneBook &phonebook)
{
    std::string fname = "";
    std::string lname = "";
    std::string nname = "";
    std::string phone = "";
    std::string secret = "";

    // Implementation of adding a new contact
    while (fname.empty())
    {
        std::cout << "Enter first name : ";
        std::getline(std::cin, fname);
    }
    while (lname.empty())
    {
        std::cout << "Enter last name : ";
        std::getline(std::cin, lname);
    }
    while (nname.empty())
    {
        std::cout << "Enter nickname : ";
        std::getline(std::cin, nname);
    }
    while (phone.empty())
    {
        std::cout << "Enter phone number : ";
        std::getline(std::cin, phone);
    }
    while (secret.empty())
    {
        std::cout << "Enter darkest secret : ";
        std::getline(std::cin, secret);
    }
    phonebook.add_contact(fname, lname, nname, phone, secret);
}

void    search_contact(PhoneBook &phonebook)
{
    int i = 0;
    int l;
    int index = 8;
    Contact curr_contact;

    if (!phonebook.is_valid(i))
    {
        std::cout << "No contact... Please ADD a contact\n\n";
        return ;
    }
    table_head();
    while (i < MAX_CONTACT)
    {
        if (!phonebook.is_valid(i))
            break ;
        else
        {
            table_delimiter();
            std::cout << "|         " << i;

            std::cout << "|";
            curr_contact = phonebook.get_contact(i);
            l = curr_contact.getFirstName().length();
            if (l < 10)
            {
                while (l++ != 10)
                    std::cout << " ";
                std::cout << curr_contact.getFirstName();
            }
            else
                std::cout << curr_contact.getFirstName().substr(0, 9) << ".";

            std::cout << "|";
            l = curr_contact.getLastName().length();
            if (l < 10)
            {
                while (l++ != 10)
                    std::cout << " ";
                std::cout << curr_contact.getLastName();
            }
            else
                std::cout << curr_contact.getLastName().substr(0, 9) << ".";

            std::cout << "|";
            l = curr_contact.getNickName().length();
            if (l < 10)
            {
                while (l++ != 10)
                    std::cout << " ";
                std::cout << curr_contact.getNickName();
            }
            else
                std::cout << curr_contact.getNickName().substr(0, 9) << ".";
        }
        std::cout << "|\n";
        i++;
    }
    for (int j = 0; j < 45; j++)
    {
        std::cout << "-";
    }
    std::cout << std::endl;
    while (true)
    {
        std::cout << "Enter contact index: ";
        if (!(std::cin >> index)) 
        {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            std::cout << "Invalid input. Please enter one of the index number.\n";
            continue;
        }
        if (index >= 0 && index < 8 && phonebook.is_valid(index))
            break;
        std::cout << "Wrong index code... Try again.\n";
    }
    std::cout << "\n";
    phonebook.display_contact_info(index);
}

void    table_delimiter()
{
    std::string delim = "|----------";
    std::cout << delim << delim << delim << delim;
    std::cout << "|\n";
}

void    table_head()
{
    for (int i = 0; i < 45; i++)
    {
        std::cout << "-";
    }
    std::cout << std::endl;
    
    std::cout << "|" << "     Index";
    std::cout << "|" << "First Name";
    std::cout << "|" << " Last Name";
    std::cout << "|" << "  Nickname";
    std::cout << "|\n";
}
