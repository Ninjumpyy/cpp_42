/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:28:51 by thomas            #+#    #+#             */
/*   Updated: 2024/11/13 13:46:21 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

//Constructor
Weapon::Weapon()
{
	
}

Weapon::Weapon(std::string type)
{
	_type = type;
}

//Destructor
Weapon::~Weapon()
{
	
}

//Methods
const std::string	&Weapon::getType() const
{
	return (_type);
}

void		Weapon::setType(std::string type)
{
	_type = type;
}