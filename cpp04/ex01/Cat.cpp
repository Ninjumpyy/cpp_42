/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:34:02 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/26 17:42:45 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Animal.hpp"
#include <iostream>

//Constructor
Cat::Cat() : Animal()
{
	std::cout << "Cat constructor called." << std::endl;
	type = "Cat";
	cat_brain = new Brain[100];
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
	delete cat_brain;
	cat_brain = NULL;
}

//Member function
void	Cat::makeSound() const
{
	std::cout << "Miaou!" << std::endl;
}
