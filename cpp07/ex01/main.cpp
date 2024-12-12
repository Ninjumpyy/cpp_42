/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:13:13 by thomas            #+#    #+#             */
/*   Updated: 2024/12/12 12:05:07 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

template <typename T>
void printElement(const T& element) {
    std::cout << element << std::endl;
}

void ft_tolower(char &arr)
{
	std::cout << static_cast<unsigned char>(std::tolower(static_cast<unsigned char>(arr))) << std::endl;
}

int	main(void)
{
	// Test 1: Integer array with a standard function
    int intArray[] = {1, 2, 3, 4, 5};
    std::cout << "Float array (print with template): " << std::endl;
    iter(intArray, 5, printElement<int>);
    std::cout << std::endl;
	
	// Test 2: Character array with a standard function (std::tolower)
	char CharArray[] = {'a', 'b', 'c', 'd', '5'};
    std::cout << "Character array (tolower function): " << std::endl;
    iter(CharArray, 5, ft_tolower); // Pass the standard function std::abs
    std::cout << std::endl;

    // Test 3: Float array with a function template
    float floatArray[] = {1.1f, 2.2f, 3.3f};
    std::cout << "Float array (print with template): " << std::endl;
    iter(floatArray, 3, printElement<float>);
    std::cout << std::endl;
	return 0;
}