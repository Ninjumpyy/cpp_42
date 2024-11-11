/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:24:51 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/11 15:21:43 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <cstdlib>
#include <limits>

void	new_contact(PhoneBook& phonebook);
void    search_contact(PhoneBook &phonebook);
void    table_delimiter();
void    table_head();

#endif