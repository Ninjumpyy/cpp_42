/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:14:55 by thomas            #+#    #+#             */
/*   Updated: 2024/11/29 11:39:31 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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

    // FragTrap tests
    std::cout << "*** FragTrap Tests ***\n\n";
    FragTrap fragtrap("Fraggy");

    // Testing unique FragTrap method
    fragtrap.highFivesGuys(); // Should work with sufficient resources

    // Test attacking with FragTrap
    fragtrap.attack("Enemy 1");
    fragtrap.attack("Enemy 2");

    // Test taking damage and repairing with FragTrap
    fragtrap.takeDamage(50);
    fragtrap.beRepaired(20);

    // Test giving high five after taking damage
    fragtrap.highFivesGuys();

    // Deplete FragTrap energy points
    for (int i = 0; i < 97; ++i)
        fragtrap.attack("Dummy");

    fragtrap.highFivesGuys(); // Should fail
    fragtrap.beRepaired(10);  // Should fail

    // Deplete hit points and test behavior
    fragtrap.takeDamage(100);
    fragtrap.highFivesGuys(); // Should fail due to no hit points
    fragtrap.attack("Enemy 3"); // Should fail due to no hit points

    // Test copying FragTrap
    FragTrap fragtrap2("Fragouuuu");
    FragTrap fragtrap3(fragtrap2); // Copy constructor
    fragtrap3.highFivesGuys();    // Should replicate the state of `fragtrap`
    fragtrap3.attack("Enemy 4");
    fragtrap3.beRepaired(10);

    FragTrap fragtrap4("AnotherFrag");
    fragtrap4 = fragtrap2; // Copy assignment operator
    fragtrap4.highFivesGuys(); // Should replicate the state of `fragtrap`
    fragtrap3.attack("Enemy 4");
    fragtrap3.beRepaired(10);

    return 0;
}