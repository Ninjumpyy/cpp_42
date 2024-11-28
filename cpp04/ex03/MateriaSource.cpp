/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:23:05 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/28 16:40:05 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"

//Constructor
MateriaSource::MateriaSource() 
{
	for (int i = 0; i < 4; i++)
	{
		_templates[i] = NULL;
	}
}

//Copy Constructor
MateriaSource::MateriaSource(const MateriaSource& other) 
{
	for (int i = 0; i < 4; i++)
	{
		if (other._templates[i])
			_templates[i] = other._templates[i]->clone();
		else
			_templates[i] = NULL;
	}
}

//Copy Assignment Operator
MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		// Cleanup existing inventory
		for (int i = 0; i < 4; i++)
		{
			delete _templates[i];
			_templates[i] = NULL;
		}

		// Deep copy inventory
		for (int i = 0; i < 4; i++)
		{
			if (other._templates[i])
				_templates[i] = other._templates[i]->clone();
		}
	}
	return (*this);
}

//Destructor
MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		delete _templates[i];
}

//Member functions
void	MateriaSource::learnMateria(AMateria* model)
{
	for (int i = 0; i < 4; i++)
	{
		if (_templates[i] == NULL)
		{
			_templates[i] = model;
			return ;
		}
	}
	delete model; // Clean up the unused model to avoid memory leaks
}

AMateria*	MateriaSource::createMateria(std::string const& type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_templates[i] && _templates[i]->getType() == type)
			return (_templates[i]->clone());
	}
	return (0);
}