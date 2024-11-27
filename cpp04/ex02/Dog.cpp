/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:34:34 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/27 12:02:36 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"
#include <iostream>

//Constructor
Dog::Dog() : Animal()
{
	std::cout << "Dog constructor called." << std::endl;
	type = "Dog";
	dog_brain = new Brain();
}

//Copy constructor
Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog copy constructor called." << std::endl;
	dog_brain = new Brain(*other.dog_brain);
}

//Copy assignment operator
Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete dog_brain;
		dog_brain = new Brain(*other.dog_brain);
	}
	std::cout << "Dog copy assignment operator called." << std::endl;
	return (*this);
}

//Destructor
Dog::~Dog()
{
	delete dog_brain;
	std::cout << "Dog destructor called." << std::endl;
}

//Member function
void	Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}

Brain*	Dog::getBrain() const
{
	return (dog_brain);
}
