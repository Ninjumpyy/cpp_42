/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:10:06 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/26 16:17:42 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include <iostream>

//Constructor
WrongCat::WrongCat() : WrongAnimal()
{
	type = "WrongCat";
	std::cout << "WrongCat constructor called." << std::endl;
}

//Copy constructor
WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << "WrongCat copy constructor called." << std::endl;
}

//Copy assignment operator
WrongCat& WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
	{
		WrongAnimal::operator=(other);
	}
	std::cout << "WrongCat copy assignment operator called." << std::endl;
	return (*this);
}

//Destructor
WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called." << std::endl;
}

//Member function
void	WrongCat::makeSound() const
{
	std::cout << "Miaou!" << std::endl;
}