/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:34:02 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/26 16:15:34 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Animal.hpp"
#include <iostream>

//Constructor
Cat::Cat() : Animal()
{
	type = "Cat";
	std::cout << "Cat constructor called." << std::endl;
}

//Copy constructor
Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat copy constructor called." << std::endl;
}

//Copy assignment operator
Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	std::cout << "Cat copy assignment operator called." << std::endl;
	return (*this);
}

//Destructor
Cat::~Cat()
{
	std::cout << "Cat destructor called." << std::endl;
}

//Member function
void	Cat::makeSound() const
{
	std::cout << "Miaou!" << std::endl;
}
