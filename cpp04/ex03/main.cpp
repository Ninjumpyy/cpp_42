/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:58:10 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/28 16:39:11 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include <iostream>

// Helper macros for colors
#define RESET   "\033[0m"   // Reset to default
#define RED		"\033[31m"	// Red
#define GREEN   "\033[32m"  // Green
#define YELLOW  "\033[33m"  // Yellow
#define BLUE    "\033[34m"  // Blue
#define MAGENTA "\033[35m"  // Magenta
#define CYAN    "\033[36m"  // Cyan

void testAMateriaAndDerived()
{
    std::cout << "\nTesting AMateria and Derived Classes...\n\n";

    // Test Ice and Cure
    Ice ice;
    Cure cure;

    std::cout << "Ice Type: " << ice.getType() << std::endl;
    std::cout << "Cure Type: " << cure.getType() << std::endl;

    // Test cloning
    AMateria* clonedIce = ice.clone();
    AMateria* clonedCure = cure.clone();

    std::cout << "Cloned Ice Type: " << clonedIce->getType() << std::endl;
    std::cout << "Cloned Cure Type: " << clonedCure->getType() << std::endl;

    // Test use
    Character target("Target");
    ice.use(target);
    cure.use(target);

    // Clean up
    delete clonedIce;
    delete clonedCure;

    std::cout << "AMateria and Derived Classes Tests Complete.\n\n";
}

void testCharacter()
{
    std::cout << "\nTesting Character...\n\n";

    Character character("Hero");
    Ice* ice = new Ice();
    Cure* cure = new Cure();

    // Equip materia
    character.equip(ice);
    character.equip(cure);

    std::cout << character.getName() << " equipped Ice and Cure.\n";

    // Use materia
    Character target("Target");
    character.use(0, target); // Should use Ice
    character.use(1, target); // Should use Cure

    // Unequip materia
    character.unequip(0);
    std::cout << character.getName() << " unequipped Ice.\n";

    // Attempt to use unequipped materia
    character.use(0, target); // Should do nothing

    // Cleanup unequipped materia
    delete ice;
    //delete cure;

    std::cout << "Character Tests Complete.\n\n";
}

void testMateriaSource()
{
    std::cout << "Testing MateriaSource...\n";

    MateriaSource source;

    Ice* ice = new Ice();
    Cure* cure = new Cure();

    // Learn materia
    source.learnMateria(ice);
    source.learnMateria(cure);
    std::cout << "Learned Ice and Cure materia.\n";

    // Create materia
    AMateria* createdIce = source.createMateria("ice");
    AMateria* createdCure = source.createMateria("cure");

    if (createdIce)
        std::cout << "Created Ice Materia: " << createdIce->getType() << std::endl;
    if (createdCure)
        std::cout << "Created Cure Materia: " << createdCure->getType() << std::endl;

    // Attempt to create non-existent materia
    AMateria* unknown = source.createMateria("fire");
    if (!unknown)
        std::cout << "Failed to create non-existent Materia: fire\n";

    // Cleanup
    delete createdIce;
    delete createdCure;

    std::cout << "MateriaSource Tests Complete.\n\n";
}

void testEdgeCases()
{
    std::cout << "Testing Edge Cases...\n";

    Character hero("Hero");
    MateriaSource source;

    // Use an empty slot
    hero.use(0, hero); // Should do nothing

    // Unequip invalid indices
    hero.unequip(-1);  // Invalid index
    hero.unequip(10);  // Invalid index

    // Create materia from an empty source
    AMateria* unknown = source.createMateria("ice");
    if (!unknown)
        std::cout << "Failed to create Materia from an empty source.\n";

    std::cout << "Edge Case Tests Complete.\n\n";
}


int	main()
{
	
	std::cout << "Testing from the subject...\n";
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
	

	std::cout << GREEN;
	testAMateriaAndDerived();
	std::cout << RESET;

	std::cout << YELLOW;
	testCharacter();
	std::cout << RESET;

	std::cout << RED;
	testMateriaSource();
	std::cout << RESET;

	std::cout << CYAN;
	testEdgeCases();
	std::cout << RESET;
	
	return (0);
}