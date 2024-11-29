/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:25:50 by thomas            #+#    #+#             */
/*   Updated: 2024/11/29 11:32:54 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

//Constructors
ScavTrap::ScavTrap() : ClapTrap()
{
	_HitPoints = 100;
	_EnergyPoints = 50;
	_AttackDamage = 20;
	std::cout << "ScavTrap constructor called for " << _Name << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	_HitPoints = 100;
	_EnergyPoints = 50;
	_AttackDamage = 20;
	std::cout << "ScavTrap constructor called for " << _Name << std::endl;
}

//Copy Constructor
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called." << std::endl;
}

//Copy Assignment Operator
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	std::cout << "ScavTrap copy assignment operator called." << std::endl;
	return (*this);
}

//Destructor
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called." << std::endl;
}

//Member functions
void	ScavTrap::attack(const std::string& target)
{
	if (_HitPoints > 0 && _EnergyPoints > 0)
	{
		_EnergyPoints--;
		std::cout << "It's a ScavTrap attack by " << _Name << ", causing " << _AttackDamage << " points of damage to " << target << std::endl;
	}
	else
	{
		if (_HitPoints == 0)
			std::cout << _Name << " cannot do its ScavTrap attack, no hit points left!" << std::endl;
		else
			std::cout << _Name << " cannot do its ScavTrap attack, no energy points left!" << std::endl;
	}
}

void	ScavTrap::guardGate(void)
{
	if (_HitPoints > 0 && _EnergyPoints > 0)
		std::cout << "ScavTrap " << _Name << " is now in Gate keeper mode!" << std::endl;
	else
	{
		if (_HitPoints == 0)
			std::cout << _Name << " cannot enter in Gate keeper mode, no hit points left!" << std::endl;
		else
			std::cout << _Name << " cannot enter in Gate keeper mode, no energy points left!" << std::endl;
	}
}