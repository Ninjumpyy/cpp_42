/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:14:55 by thomas            #+#    #+#             */
/*   Updated: 2024/11/29 11:05:06 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
    // ClapTrap tests
    std::cout << "*** ClapTrap Tests ***\n\n";
    
    ClapTrap noname;
    ClapTrap clappy("Clappy");
    ClapTrap claptrap(clappy);
    claptrap = noname;

    noname.attack("Enemy 1");
    clappy.attack("Enemy 2");
    claptrap.attack("Ennemy 3");

    clappy.takeDamage(3);
	clappy.beRepaired(5); // Repair when energy points are available

    clappy.takeDamage(11); // Test for more damage than current hit points
    clappy.beRepaired(20); 

    // Deplete energy points to test behavior
    for (int i = 0; i < 7; ++i)
        clappy.attack("Dummy");

    // Attempt to attack and repair when out of energy points
    clappy.attack("Enemy 3");
    clappy.beRepaired(5);

    // Deplete hit points to test behavior
    clappy.takeDamage(100); // Ensure hit points are 0

    // Attempt to attack and repair when out of hit points
    clappy.attack("Enemy 4");
    clappy.beRepaired(10);

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
    scavtrap3.takeDamage(10);
    scavtrap3.beRepaired(10);
    scavtrap3.guardGate();

    scavtrap2 = scavtrap; // Copy assignment operator
    scavtrap2.attack("Assigned Enemy");
    scavtrap2.takeDamage(10);
    scavtrap2.beRepaired(10);
    scavtrap2.guardGate();

    // Deplete ScavTrap energy and health
    for (int i = 0; i < 48; ++i)
        scavtrap.attack("Enemy");

    scavtrap.attack("Last Enemy"); // Should fail
    scavtrap.beRepaired(50); // Should fail
    scavtrap.takeDamage(100); // Deplete health completely
    scavtrap.attack("Last Enemy"); // Should fail
    scavtrap.beRepaired(50); // Should fail
    
    return 0;
}