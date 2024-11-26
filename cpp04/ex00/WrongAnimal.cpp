/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:11:45 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/26 16:16:37 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

//Constructor
WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "WrongAnimal constructor called." << std::endl;
}

//Copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type)
{
	std::cout << "WrongAnimal copy constructor called." << std::endl;
}

//Copy assignment operator
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
	{
		type = other.type;
	}
	std::cout << "WrongAnimal copy assignment operator called." << std::endl;
	return (*this);
}

//Destructor
WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called." << std::endl;
}

//Member Functions
void	WrongAnimal::makeSound() const
{
	std::cout << "Random WrongAnimal Sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (type);
}