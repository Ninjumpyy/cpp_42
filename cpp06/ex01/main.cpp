/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:21:06 by thomas            #+#    #+#             */
/*   Updated: 2024/12/10 17:01:44 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main() 
{
    Data originalData;  // Create an example Data object
	originalData.value = 42;
	originalData.name = "Test";
    Data* originalPtr = &originalData;

    uintptr_t serialized = Serializer::serialize(originalPtr); // Serialize the pointer
    Data* deserialized = Serializer::deserialize(serialized); // Deserialize the pointer

    std::cout << "Original pointer: " << originalPtr << std::endl;
    std::cout << "Serialized value: " << serialized << std::endl;
    std::cout << "Deserialized pointer: " << deserialized << std::endl;
    std::cout << "Value: " << deserialized->value << std::endl;
	std::cout << "Name: " << deserialized->name << std::endl;

    return 0;
}