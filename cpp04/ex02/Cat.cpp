/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:34:02 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/27 12:03:21 by tle-moel         ###   ########.fr       */
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
	cat_brain = new Brain();
}

//Copy constructor
Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat copy constructor called." << std::endl;
	cat_brain = new Brain(*other.cat_brain);
}

//Copy assignment operator
Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete cat_brain;
		cat_brain = new Brain(*other.cat_brain);
	}
	std::cout << "Cat copy assignment operator called." << std::endl;
	return (*this);
}

//Destructor
Cat::~Cat()
{
	delete cat_brain;
	std::cout << "Cat destructor called." << std::endl;
}

//Member function
void	Cat::makeSound() const
{
	std::cout << "Miaou!" << std::endl;
}

Brain*	Cat::getBrain() const
{
	return (cat_brain);
}
