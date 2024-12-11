/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:09:11 by thomas            #+#    #+#             */
/*   Updated: 2024/12/11 15:58:33 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include <iostream>

int main(void)
{
	std::srand(std::time(0));

	std::cout << "Random Test\n";

	Base* obj = generate();
	identify(obj);
	identify(*obj);

	std::cout << "Pointers Test\n";

	Base* objA = new A();
    Base* objB = new B();
    Base* objC = new C();

    identify(objA); // Output: A
    identify(objB); // Output: B
    identify(objC); // Output: C

    delete objA;
    delete objB;
    delete objC;

	std::cout << "Reference Test\n";

	A a;
    B b;
    C c;

    identify(a); // Output: A
    identify(b); // Output: B
    identify(c); // Output: C

	return (0);
}