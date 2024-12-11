/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:21:16 by thomas            #+#    #+#             */
/*   Updated: 2024/12/11 16:02:28 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include <iostream>
#include <typeinfo>

Base* generate(void)
{
	int randomNumber = std::rand() % 3;
	
	switch (randomNumber)
	{
		case (0):
			return new A();
		case (1):
			return new B();
		case (2):
			return new C();
		default:
			return NULL;
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	try {
		dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (const std::bad_cast&) {
		//Not type A
	}
	try {
		dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (const std::bad_cast&) {
		//Not type B
	}
	try {
		dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (const std::bad_cast&) {
		//Not type C
	}
}