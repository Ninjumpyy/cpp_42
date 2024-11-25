/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:14:55 by thomas            #+#    #+#             */
/*   Updated: 2024/11/25 16:30:21 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main()
{
    std::cout << "** CLAPTRAP TEST BEGIN **\n\n";
    ClapTrap claptrap("Clappy");
	ClapTrap claptrap2("Billy");

    claptrap.attack("Enemy 1");
    claptrap.attack("Enemy 2");

    claptrap.takeDamage(3);
	claptrap.beRepaired(5); // Repair when energy points are available

    claptrap.takeDamage(15); // Test for more damage than current hit points
    claptrap.beRepaired(20); // Repair more than hit points would need

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

    // ScavTrap tests
    std::cout << "\n** SCAVTRAP TEST BEGIN **\n\n";
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

    for (int i = 0; i < 50; ++i)
        scavtrap.attack("Enemy");

    scavtrap.takeDamage(100); // Deplete health completely
    scavtrap.attack("Last Enemy"); // Should fail
    scavtrap.beRepaired(50); // Should fail

    // FragTrap tests
    std::cout << "\n** FRAGTRAP TEST BEGIN **\n\n";
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
    FragTrap fragtrap2(fragtrap); // Copy constructor
    fragtrap2.highFivesGuys();    // Should replicate the state of `fragtrap`

    FragTrap fragtrap3("AnotherFrag");
    fragtrap3 = fragtrap; // Copy assignment operator
    fragtrap3.highFivesGuys(); // Should replicate the state of `fragtrap`

    // DiamondTrap tests
    std::cout << "\n** DIAMOND TEST BEGIN **\n\n";
    // Default constructor
    DiamondTrap dt1;
    dt1.whoAmI();
    dt1.attack("Enemy");
    dt1.attack("Default Enemy"); // Should use ScavTrap's attack
    dt1.takeDamage(20); // From ClapTrap
    dt1.beRepaired(10); // From ClapTrap

    // Parameterized constructor
    DiamondTrap dt2("Diamondy");
    dt2.whoAmI();
    dt2.attack("Enemy");
    for (int i = 0; i < 50; ++i)
    {
        dt2.attack("Random Enemy");
    }
    dt2.attack("Final Enemy"); // Should fail due to no energy left
    dt2.beRepaired(10); // Should fail due to no energy left

    // Copy constructor
    DiamondTrap dt3(dt2);
    dt3.whoAmI();
    dt3.guardGate();
    dt3.highFivesGuys();

    // Copy assignment operator
    dt1 = dt2;
    dt1.whoAmI();

    return 0;
}