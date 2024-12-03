/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:50:40 by tle-moel          #+#    #+#             */
/*   Updated: 2024/12/03 18:09:47 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    try {
        // Create a Bureaucrat with a valid grade
        Bureaucrat john("John", 50);
        std::cout << john << std::endl;

        // Create a Form with valid grades
        Form taxForm("Tax Form", 30, 40); // Requires grade 30 to sign and 40 to execute
        std::cout << taxForm << std::endl;

        // Attempt to sign the form (should fail due to insufficient grade)
        john.signForm(taxForm);

        // Create a Bureaucrat with higher authority
        Bureaucrat alice("Alice", 20); // High enough grade to sign
        std::cout << alice << std::endl;

        // Sign the form (should succeed)
        alice.signForm(taxForm);
        std::cout << taxForm << std::endl;

        // Test exceptions by creating a form with invalid grades
        Form invalidForm("Invalid Form", 0, 200); // Invalid grades
    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}

