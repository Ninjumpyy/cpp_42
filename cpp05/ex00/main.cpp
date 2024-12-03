/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:50:40 by tle-moel          #+#    #+#             */
/*   Updated: 2024/12/03 17:12:50 by tle-moel         ###   ########.fr       */
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
        Bureaucrat b("Alice", 1);
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
		std::cout << "Decrementation successfull" << std::endl;
		a.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
    return 0;
}
