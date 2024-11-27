/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:04:22 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/27 17:05:16 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"

//Constructor
Ice::Ice(std::string const& type) : AMateria(type) {}

//Copy Constructor
Ice::Ice(const Ice& other) : AMateria(other) {}

//Copy Assignment Operator
Ice& Ice::operator=(const Ice& other)
{
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	return (*this);
}

//Destructor
Ice::~Ice() {}

//Member functions to override
AMateria* Ice::clone() const
{
	AMateria* clone = new Ice("ice");
	return (clone);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}