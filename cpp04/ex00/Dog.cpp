/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:34:34 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/26 16:15:20 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"
#include <iostream>

//Constructor
Dog::Dog() : Animal()
{
	type = "Dog";
	std::cout << "Dog constructor called." << std::endl;
}

//Copy constructor
Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog copy constructor called." << std::endl;
}

//Copy assignment operator
Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	std::cout << "Dog copy assignment operator called." << std::endl;
	return (*this);
}

//Destructor
Dog::~Dog()
{
	std::cout << "Dog destructor called." << std::endl;
}

//Member function
void	Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}
