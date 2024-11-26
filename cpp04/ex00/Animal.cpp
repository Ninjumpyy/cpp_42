/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:32:47 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/26 16:16:14 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

//Constructor
Animal::Animal() : type("Animal")
{
	std::cout << "Animal constructor called." << std::endl;
}

//Copy constructor
Animal::Animal(const Animal& other) : type(other.type)
{
	std::cout << "Animal copy constructor called." << std::endl;
}

//Copy assignment operator
Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
	{
		type = other.type;
	}
	std::cout << "Animal copy assignment operator called." << std::endl;
	return (*this);
}

//Destructor
Animal::~Animal()
{
	std::cout << "Animal destructor called." << std::endl;
}

//Virtual Function
void	Animal::makeSound() const
{
	std::cout << "Random Animal Sound" << std::endl;
}

//Member Function
std::string Animal::getType() const
{
	return (type);
}