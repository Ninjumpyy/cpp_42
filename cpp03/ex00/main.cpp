/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:14:55 by thomas            #+#    #+#             */
/*   Updated: 2024/11/25 11:28:11 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
    ClapTrap claptrap("Clappy");
	ClapTrap claptrap2("Billy");

    claptrap.attack("Enemy 1");
    claptrap2.attack("Enemy 2");

    claptrap.takeDamage(3);
	claptrap.beRepaired(5); // Repair when energy points are available

    claptrap.takeDamage(15); // Test for more damage than current hit points
    claptrap.beRepaired(20); 

    // Deplete energy points to test behavior
    for (int i = 0; i < 10; ++i)
        claptrap2.attack("Dummy");

    // Attempt to attack and repair when out of energy points
    claptrap2.attack("Enemy 3");
    claptrap2.beRepaired(5);

    // Deplete hit points to test behavior
    claptrap2.takeDamage(100); // Ensure hit points are 0

    // Attempt to attack and repair when out of hit points
    claptrap2.attack("Enemy 4");
    claptrap2.beRepaired(10);

    ClapTrap claptrap3;
    
    claptrap3.attack("Enemy 3");
    claptrap3 = claptrap;
    claptrap3.attack("Ennemy 3");

    ClapTrap claptrap4(claptrap2);

    claptrap4.attack("Ennemy 4");

    return 0;
}