/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:51:47 by thomas            #+#    #+#             */
/*   Updated: 2024/11/13 13:40:22 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <string>
#include <iostream>

//Constructor
HumanA::HumanA(std::string name, Weapon& weapon) : _weapon(weapon)
{
	_name = name;
}

//Destructor
HumanA::~HumanA() {}

//Methods
void	HumanA::attack()
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}