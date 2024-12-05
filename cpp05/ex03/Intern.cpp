/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:19:53 by thomas            #+#    #+#             */
/*   Updated: 2024/12/05 14:23:06 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

//Constructor
Intern::Intern() {}

//Copy Constructor
Intern::Intern(const Intern& other) {(void)other;}

//Copy Assignment Operator
Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return (*this);
}

//Destructor
Intern::~Intern() {}

//Method
AForm*	Intern::makeForm(std::string form_name, std::string target) const
{
	std::string possibility[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	int i = 0;
	while (i < 3 && form_name != possibility[i])
		i++;
	switch (i)
	{
		case 0:
			std::cout << "Intern creates " << form_name << std::endl;
			return (new ShrubberyCreationForm(target));
		case 1:
			std::cout << "Intern creates " << form_name << std::endl;
			return (new RobotomyRequestForm(target));
		case 2:
			std::cout << "Intern creates " << form_name << std::endl;
			return (new PresidentialPardonForm(target));
		default:
			throw NotFind();
	}
}

//Exception
const char *Intern::NotFind::what() const throw()
{
	return ("Type of form unknown.");
}