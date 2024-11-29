/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:14:55 by thomas            #+#    #+#             */
/*   Updated: 2024/11/29 10:51:16 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
    ClapTrap noname;
    ClapTrap clappy("Clappy");
    ClapTrap billy("Billy");
    ClapTrap copy_billy(billy);
    ClapTrap copy_clappy;
    copy_clappy = clappy;

    noname.attack("Enemy 1");
    clappy.attack("Enemy 2");
    copy_billy.attack("Ennemy 3");

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

    return 0;
}