/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:50:40 by tle-moel          #+#    #+#             */
/*   Updated: 2024/12/04 10:13:46 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    try 
	{
        Bureaucrat b("John", 151); // Invalid grade
    } 
	catch (std::exception &e) 
	{
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try 
	{
        Bureaucrat b("Alice", 2);
		b.incrementGrade();
		std::cout << "Incrementation successfull" << std::endl; //Should be fine
        b.incrementGrade(); // Will throw GradeTooHighException
    } 
	catch (std::exception &e) 
	{
        std::cout << "Exception: " << e.what() << std::endl;
    }

	try
	{
		Bureaucrat a("Bob", 149);
		a.decrementGrade();
		std::cout << "Decrementation successfull" << std::endl; //Should be fine
		a.decrementGrade(); // Will throw GradeTooLowException
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
    return 0;
}
