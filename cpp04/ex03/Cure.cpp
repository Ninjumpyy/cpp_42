/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:04:13 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/27 17:04:58 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Cure.hpp"

//Constructor
Cure::Cure(std::string const& type) : AMateria(type) {}

//Copy Constructor
Cure::Cure(const Cure& other) : AMateria(other) {}

//Copy Assignment Operator
Cure& Cure::operator=(const Cure& other)
{
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	return (*this);
}

//Destructor
Cure::~Cure() {}

//Member functions to override
AMateria* Cure::clone() const
{
	AMateria* clone = new Cure("cure");
	return (clone);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}