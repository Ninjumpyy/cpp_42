/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:43:26 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/29 13:33:10 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

//Constructors
DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), ScavTrap(), FragTrap(), _Name("Default")
{
	_EnergyPoints = 50;
	std::cout << "DiamondTrap constructor called for " << _Name << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _Name(name)
{
	_EnergyPoints = 50;
	std::cout << "DiamondTrap constructor called for " << _Name << std::endl;
}

//Copy Constructor
DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), _Name(other._Name)
{
	std::cout << "DiamondTrap copy constructor called." << std::endl;
}

//Copy Assignment Operator
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		_Name = other._Name;
		ClapTrap::operator=(other);
	}
	std::cout << "DiamondTrap copy assignment operator called." << std::endl;
	return (*this);
}

//Destructor
DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called for " << DiamondTrap::_Name << std::endl;
}

//Member Functions
void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "I am " << DiamondTrap::_Name << ". My ClapTrap name is " << ClapTrap::_Name << std::endl;
}
