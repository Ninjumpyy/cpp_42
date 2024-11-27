/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:46:48 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/27 14:55:28 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
#include <iostream>

// Helper macros for colors
#define RESET   "\033[0m"   // Reset to default
#define RED		"\033[31m"	// Red
#define GREEN   "\033[32m"  // Green
#define YELLOW  "\033[33m"  // Yellow
#define BLUE    "\033[34m"  // Blue
#define MAGENTA "\033[35m"  // Magenta
#define CYAN    "\033[36m"  // Cyan

void test_deep_copy()
{
	std::cout << "\nDeep Copy\n\n";
	Dog dog1;
	Dog dog2 = dog1; // Copy constructor
	Dog dog3;

	std::cout << dog1.getType() << ": ";
	dog1.makeSound(); 
	std::cout << dog2.getType() << ": ";
	dog2.makeSound();

	dog3 = dog1; // Assignment operator
	std::cout << "dog3 type after assignment: " << std::endl;
	std::cout << dog3.getType() << ": ";
	dog3.makeSound();

	Cat cat1;

	cat1.getBrain()->setIdea(0, "Chasing the ball");
	Cat cat2(cat1);
	cat2.getBrain()->setIdea(0, "Eating food");

	std::cout << "Cat1 Brain Idea 0: " << cat1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Cat2 Brain Idea 0: " << cat2.getBrain()->getIdea(0) << std::endl;
}

void test_polymorphism_with_arrays(void)
{
	std::cout << "\nPolymorphism with Arrays\n\n";
	const Animal* animals[3];
	//animals[0] = new Animal(); Animal class can't be instantiated otherwise error...
	animals[0] = new Cat();
	animals[1] = new Dog();
	animals[2] = new Cat();

	for (int i = 0; i < 3; ++i) {
		std::cout << animals[i]->getType() << ": ";
		animals[i]->makeSound();
	}

	// Free memory
	for (int i = 0; i < 3; ++i) 
	{
		delete animals[i];
	}
}

void test_assignment_with_polymorphism()
{
	std::cout << "\nAssignment with Polymorphism\n\n";
	Animal* animal = new Dog();
	Animal* anotherAnimal = new Cat();

	std::cout << "anotherAnimal: " << anotherAnimal->getType() << std::endl;
	delete anotherAnimal;
	anotherAnimal = animal;

	std::cout << "anotherAnimal after assignment: " << anotherAnimal->getType() << std::endl;
	anotherAnimal->makeSound();

	delete animal;
}
/* Animal class can't be instantiated otherwise error...
void test_object_slicing()
{
	std::cout << "\nObject slicing\n\n";
	Dog dog;
	Animal animal = dog;

	std::cout << "animal type after slicing: " << animal.getType() << std::endl;
	animal.makeSound();
}*/

void	test_wrong_classes()
{
	std::cout << "\nTest with the wrong classes\n\n";
	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* i = new WrongCat();

	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	meta->makeSound();

	delete(meta);
	delete(i);
}

void	test_ex01(void)
{
	std::cout << "\nTest for the Brain class\n\n";
	Animal	*array[100];

	for (int i = 0; i < 100; i++)
	{
		if (i < 50)
			array[i] = new Dog();
		else
			array[i] = new Cat();
	}

	for (int i = 0; i < 100; i++)
		delete array[i];
}

int main()
{
	std::cout << "Test from the subject\n\n";
	//const Animal* meta = new Animal(); // Animal class can't be instantiated otherwise error...
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	//meta->makeSound();

	//delete(meta);
	delete(j);
	delete(i);

	std::cout << GREEN;
	test_deep_copy();
	std::cout << RESET;
	
	std::cout << YELLOW;
	test_polymorphism_with_arrays();
	std::cout << RESET;

	std::cout << RED;
	test_assignment_with_polymorphism();
	std::cout << RESET;

	/*
	std::cout << MAGENTA;
	test_object_slicing();
	std::cout << RESET;
	*/

	std::cout << CYAN;
	test_wrong_classes();
	std::cout << RESET;

	std::cout << GREEN;
	test_ex01();
	std::cout << RESET;

    return (0);
}
