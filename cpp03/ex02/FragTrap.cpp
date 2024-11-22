/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:13:08 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/22 17:27:03 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

//Constructor
FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	_HitPoints = 100;
	_EnergyPoints = 100;
	_AttackDamage = 30;
	std::cout << "FragTrap constructor called for " << _Name << std::endl;
}

//Copy Constructor
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	_HitPoints = other._HitPoints;
	_EnergyPoints = other._EnergyPoints;
	_AttackDamage = other._AttackDamage;
	std::cout << "FragTrap copy constructor called." << std::endl;
}

//Copy Assignment Operator
FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	std::cout << "FragTrap copy assignment operator called." << std::endl;
	return (*this);
}

//Destructor
FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called for " << _Name << std::endl;
}

//Member Function
void	FragTrap::highFivesGuys(void)
{
	if (_HitPoints > 0 && _EnergyPoints > 0)
		std::cout << _Name << " is giving you a high five!" << std::endl;
	else
	{
		if (_HitPoints == 0)
			std::cout << _Name << " cannot give you a high five, no hit points left!" << std::endl;
		else
			std::cout << _Name << " cannot give you a high five, no energy points left!" << std::endl;
	}
}