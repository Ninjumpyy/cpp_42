/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:17:47 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/29 17:46:57 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"
#include <iostream>

//Constructor
Character::Character(std::string const& name) : _name(name)
{
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
	}
	for (int i = 0; i < 100; i++)
	{
		_unequiped[i] = NULL;
	}
}

//Copy Constructor
Character::Character(const Character& other) : _name(other._name)
{
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
	for (int i = 0; i < 100; i++)
	{
		if (other._unequiped[i])
			_unequiped[i] = other._unequiped[i]->clone();
		else
			_unequiped[i] = NULL;
	}
}

//Copy Assignment Operator
Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		// Cleanup existing inventory
		for (int i = 0; i < 4; i++)
		{
			delete _inventory[i];
			_inventory[i] = NULL;
		}

		// Deep copy inventory
		for (int i = 0; i < 4; i++)
		{
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
		}

		for (int i = 0; i < 100; i++)
		{
			delete _unequiped[i];
			_unequiped[i] = NULL;
		}
		for (int i = 0; i < 100; i++)
		{
			if (other._unequiped[i])
				_unequiped[i] = other._unequiped[i]->clone();
		}
	}
	return (*this);
}

//Destructor
Character::~Character() 
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
		{
			delete _inventory[i];
		}
	}
	int i = 0;
	while (i < 100)
	{
		if (_unequiped[i])
			delete _unequiped[i];
		i++;
	}
}

//Member functions to override
std::string const& Character::getName() const
{
	return (_name);
}

void	Character::equip(AMateria* m)
{
	if (m == NULL)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == m)
			return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			return ;
		}
	}
	delete m;
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && _inventory[idx])
	{
		int i = 0;
		while (i < 100 && _unequiped[i] != NULL)
			i++;
		_unequiped[i] = _inventory[idx];
		_inventory[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && _inventory[idx] != NULL)
		_inventory[idx]->use(target);
}