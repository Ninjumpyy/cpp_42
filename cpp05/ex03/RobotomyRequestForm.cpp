/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:30:51 by thomas            #+#    #+#             */
/*   Updated: 2024/12/05 11:32:25 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>

//Constructors
RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), _target("Default") {}
RobotomyRequestForm::RobotomyRequestForm(std::string target):  AForm("RobotomyRequestForm", 72, 45), _target(target) {}

//Copy Constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm(other), _target(other._target) {}

//Copy Assignment Operator
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	(void)other;
	return (*this);
}

//Destructor
RobotomyRequestForm::~RobotomyRequestForm() {}

//Method to override
void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	canExecute(executor);
	std::cout << "* Brrrrrrr... Drrrrrrrrrr... Vrrrrrrrrrr... *\n";
	int random_nb = rand() % 2;
	if (random_nb)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Robotomy failed...." << std::endl;
}
