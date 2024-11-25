/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:14:55 by thomas            #+#    #+#             */
/*   Updated: 2024/11/25 11:47:07 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
    std::cout << "*** ClapTrap Tests ***\n\n";
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

    // ScavTrap tests
    std::cout << "\n*** ScavTrap Tests ***\n\n";
    ScavTrap scavtrap("Scavvy");
    ScavTrap scavtrap2("Guardian");

    scavtrap.attack("Enemy 1");
    scavtrap.guardGate();

    scavtrap.takeDamage(20);
    scavtrap.beRepaired(20);

    // Test copying
    ScavTrap scavtrap3(scavtrap); // Copy constructor
    scavtrap3.attack("Copied Enemy");
    scavtrap3.guardGate();

    scavtrap2 = scavtrap; // Copy assignment operator
    scavtrap2.attack("Assigned Enemy");
    scavtrap2.guardGate();

    // Deplete ScavTrap energy and health
    for (int i = 0; i < 48; ++i)
        scavtrap.attack("Enemy");

    scavtrap.takeDamage(100); // Deplete health completely
    scavtrap.attack("Last Enemy"); // Should fail
    scavtrap.beRepaired(50); // Should fail

    ScavTrap test;
    test.attack("Someone");

    return 0;
}