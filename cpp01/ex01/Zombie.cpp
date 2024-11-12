/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:13:08 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/12 17:29:12 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>
#include <iostream>

//Constructors
Zombie::Zombie()
{
	
}

Zombie::Zombie(std::string name)
{
	_name = name;
}

//Destructor
Zombie::~Zombie()
{
	std::cout << _name << " destroyed.\n";
}

//Methods
void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}