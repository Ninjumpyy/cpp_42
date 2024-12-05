/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:30:43 by thomas            #+#    #+#             */
/*   Updated: 2024/12/05 10:52:28 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

//Constructors
PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), _target("Default") {}
PresidentialPardonForm::PresidentialPardonForm(std::string target):  AForm("PresidentialPardonForm", 25, 5), _target(target) {}

//Copy Constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): AForm(other), _target(other._target) {}

//Copy Assignment Operator
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	(void)other;
	return (*this);
}

//Destructor
PresidentialPardonForm::~PresidentialPardonForm() {}

//Method to override
void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	canExecute(executor);
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}