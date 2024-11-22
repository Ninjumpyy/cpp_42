/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:54:55 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/22 15:49:57 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>

//Constructor
Zombie::Zombie()
{
	
}

// Zombie::Zombie(std::string zombieName) : name(zombieName) {}
Zombie::Zombie(std::string zombie_name)
{
	name = zombie_name;
}

//Destructor
Zombie::~Zombie()
{
	std::cout << name << "...........(dead).\n";
}

//Methods
void	Zombie::announce(void)
{
	std::cout << Zombie::name << ": BraiiiiiiinnnzzzZ...\n";
}