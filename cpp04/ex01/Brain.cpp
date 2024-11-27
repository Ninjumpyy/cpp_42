/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:53:09 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/27 10:38:05 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

//Constructor
Brain::Brain() 
{
	for (int i = 0; i < 100; i++)
		ideas[i] = "empty";
	std::cout << "Brain default constructor called." << std::endl;
}

//Copy constructor
Brain::Brain(const Brain& other)
{
	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
	std::cout << "Brain copy constructor called." << std::endl;
}

//Copy Assignment Operator
Brain& Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	}
	std::cout << "Brain copy assignment operator called." << std::endl;
	return (*this);
}

//Destructor
Brain::~Brain() 
{
	std::cout << "Brain destructor called." << std::endl;
}

//Member functions
std::string	Brain::getIdea(const unsigned int index) const
{
	if (index < 100)
		return (ideas[index]);
	return ("");
}

void	Brain::setIdea(const unsigned int index, const std::string idea)
{
	if (index < 100)
		ideas[index] = idea;
}