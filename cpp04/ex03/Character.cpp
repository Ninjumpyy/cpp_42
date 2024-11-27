/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:17:47 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/27 17:40:11 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

//Constructor
Character::Character(std::string const& name) : _name(name)
{
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
	}
}

//Copy Constructor
Character::Character(const Character& other) : _name(other._name)
{
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = other._inventory[i];
	}
}

//Copy Assignment Operator
Character& Character::operator=(const Character& other)
{
	(void)other;
	return (*this);
}

//Destructor
Character::~Character() {}

//Member functions to override
std::string const& Character::getName() const
{
	return (_name);
}

void	Character::equip(AMateria* m)
{
	int i = 0;
	while (i < 4 && _inventory[i] == NULL)
		i++;
	if (i != 4)
		_inventory[i] = m;
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && _inventory[idx] != NULL)
		_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && _inventory[idx] != NULL)
		_inventory[idx]->use(target);
}