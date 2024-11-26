/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:53:09 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/26 17:44:38 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

//Constructor
Brain::Brain() 
{
	std::cout << "Brain default constructor called." << std::endl;
}

//Copy constructor
Brain::Brain(const Brain& other) {}

//Copy Assignment Operator
Brain& Brain::operator=(const Brain& other)
{
	
}

//Destructor
Brain::~Brain() {}