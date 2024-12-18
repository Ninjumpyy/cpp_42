/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:05:42 by thomas            #+#    #+#             */
/*   Updated: 2024/12/18 16:39:12 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib> // For rand()
#include <ctime>   // For time()

void testBasic() {
    std::cout << "--- Basic Test ---" << std::endl;

    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
}

void testExceptions() {
    std::cout << "\n--- Exceptions Test ---" << std::endl;

    try {
        Span sp(2);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3); // Exceeds capacity
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Span sp(1);
        sp.addNumber(5);
        sp.shortestSpan(); // Not enough elements
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void testAddRange() {
    std::cout << "\n--- Add Range Test ---" << std::endl;

    int arr[] = {10, 20, 30, 40, 50}; // Use an array for initialization
    std::vector<int> vec(arr, arr + 5); // Initialize vector with array elements
    Span sp(10);

    sp.addRange(vec.begin(), vec.end());
    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

    try {
        int extraArr[] = {60, 70, 80, 90, 100, 110}; // Use an array for the extra range
        std::vector<int> extra(extraArr, extraArr + 6); // Initialize vector with array elements
        sp.addRange(extra.begin(), extra.end());
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void testLargeSpan() {
    std::cout << "\n--- Large Span Test ---" << std::endl;

    Span sp(10000);
    for (int i = 0; i < 10000; ++i) {
        sp.addNumber(rand() % 100000); // Add random numbers
    }

    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
}

void testCopyAndAssignment() {
    std::cout << "\n--- Copy and Assignment Test ---" << std::endl;

    Span sp1(5);
    sp1.addNumber(1);
    sp1.addNumber(10);
    sp1.addNumber(20);

    Span sp2 = sp1; // Copy constructor
    std::cout << "Shortest Span (copy): " << sp2.shortestSpan() << std::endl;

    Span sp3(10);
    sp3 = sp1; // Assignment operator
    std::cout << "Shortest Span (assignment): " << sp3.shortestSpan() << std::endl;
}

int main() {
    srand(time(0)); // Seed for random number generation

    testBasic();
    testExceptions();
    testAddRange();
    testLargeSpan();
    testCopyAndAssignment();

    return 0;
}

