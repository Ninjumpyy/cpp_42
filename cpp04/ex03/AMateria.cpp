/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:59:28 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/28 15:08:39 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

//Constructor
AMateria::AMateria(std::string const& type) : _type(type) {}

//Copy Constructor
AMateria::AMateria(const AMateria& other) : _type(other._type) {}

//Copy Assignment Operator
AMateria& AMateria::operator=(const AMateria& other)
{
	if (this != &other)
	{
		_type = other._type;
	}
	return (*this);
}

//Destructor
AMateria::~AMateria() {}

//Member functions
std::string const& AMateria::getType() const
{
	return (_type);
}

AMateria* AMateria::clone() const 
{
	//virtual function to be override by derived class
	return (NULL);
}

void	AMateria::use(ICharacter& target) 
{
	//virtual function to be override by derived class
	(void) target;
}

