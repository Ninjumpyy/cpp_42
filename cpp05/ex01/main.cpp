/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:50:40 by tle-moel          #+#    #+#             */
/*   Updated: 2024/12/04 11:20:02 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    try {
        // Test 1: Bureaucrat with valid grade
        Bureaucrat john("John", 50);
        std::cout << john << std::endl;

        // Test 2: Form with valid grades
        Form taxForm("Tax Form", 30, 40);
        std::cout << taxForm << std::endl;

        // Test 3: Attempt to sign the form with insufficient grade
        std::cout << "Attempting to sign Tax Form with John:" << std::endl;
        john.signForm(taxForm);

        // Test 4: Create a higher-grade Bureaucrat and sign the form
        Bureaucrat alice("Alice", 20);
        std::cout << alice << std::endl;

        std::cout << "Attempting to sign Tax Form with Alice:" << std::endl;
        alice.signForm(taxForm);
        std::cout << taxForm << std::endl;

        // Test 5: Attempt to create a form with invalid grades
        try 
		{
            Form invalidForm("Invalid Form", 0, 200); // Invalid grades
        } 
		catch (std::exception &e) 
		{
            std::cerr << "Exception caught while creating a form: " << e.what() << std::endl;
        }

        // Test 6: Test Bureaucrat at the highest valid grade
        Bureaucrat elite("Elite", 1);
        std::cout << elite << std::endl;

        // Test 7: Bureaucrat at the lowest valid grade
        Bureaucrat junior("Junior", 150);
        std::cout << junior << std::endl;

    } 
	catch (std::exception &e) 
	{
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
