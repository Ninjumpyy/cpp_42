/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:14:45 by thomas            #+#    #+#             */
/*   Updated: 2024/11/22 14:45:13 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//Constructor
ClapTrap::ClapTrap(const std::string& name) : _Name(name), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
	std::cout << "ClapTrap constructor called." << std::endl;
}

//Copy Constructor
ClapTrap::ClapTrap(const ClapTrap& other) : _Name(other._Name), _HitPoints(other._HitPoints), _EnergyPoints(other._EnergyPoints), _AttackDamage(other._AttackDamage)
{
	std::cout << "ClapTrap copy constructor called." << std::endl;
}

//Copy Assignment Operator
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap copy assignment operator called. " << std::endl;
	if (this != &other)
	{
		_Name = other._Name;
		_HitPoints = other._HitPoints;
		_EnergyPoints = other._EnergyPoints;
		_AttackDamage = other._AttackDamage;
	}
	return (*this);
}

//Destructor
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called." << std::endl;
}

//Member Functions
void	ClapTrap::attack(const std::string& target)
{
	if (_HitPoints > 0 && _EnergyPoints > 0)
	{
		_EnergyPoints--;
		std::cout << _Name << " attacks " << target << ", causing " << _AttackDamage << " points of damage!" << std::endl;
	}
	else
	{
		if (_HitPoints == 0)
			std::cout << _Name << " cannot attack, no hit points left!" << std::endl;
		else
			std::cout << _Name << " cannot attack, no energy points left!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_HitPoints > 0)
	{
		if (_HitPoints > amount)
			_HitPoints -= amount;
		else
			_HitPoints = 0;
		std::cout << _Name << " takes " << amount << " points of damage. He now has " << _HitPoints << " hit points." << std::endl;
	}
	else
		std::cout << _Name << " has no hit points left!" << std::endl;

}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_HitPoints > 0 && _EnergyPoints > 0)
	{
		_EnergyPoints--;
		_HitPoints += amount;
		std::cout << _Name << " repairs itself, it gets " << amount << " hit points back. He now has " << _HitPoints << " hit points." << std::endl;
	}
	else
	{
		if (_HitPoints == 0)
			std::cout << _Name << " cannot be repaired, no hit points left!" << std::endl;
		else
			std::cout << _Name << " cannot be repaired, no energy points left!" << std::endl;
	}
}