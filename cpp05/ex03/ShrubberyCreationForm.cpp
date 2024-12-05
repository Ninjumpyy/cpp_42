/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:30:57 by thomas            #+#    #+#             */
/*   Updated: 2024/12/05 11:29:20 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

//Constructors
ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), _target("Default") {}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target):  AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

//Copy Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm(other), _target(other._target) {}

//Copy Assignment Operator
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	(void)other;
	return (*this);
}

//Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {}

//Method to override
void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	canExecute(executor);
	std::string filename = _target + "_shrubbery";
	std::ofstream file(filename.c_str());
	if (!file)
		throw std::runtime_error("Failed to create the shrubbery file.");
	file << "   *   " << std::endl;
	file << "  ***  " << std::endl;
	file << " ***** " << std::endl;
	file << "*******" << std::endl;
	file << "  |||  " << std::endl;
	file.close();
	std::cout << "Shrubbery created in " << _target << "_shrubbery file." << std::endl;
}
