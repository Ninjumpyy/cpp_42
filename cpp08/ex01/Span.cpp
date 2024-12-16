/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-moel <tle-moel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:05:50 by thomas            #+#    #+#             */
/*   Updated: 2024/12/16 17:02:42 by tle-moel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

//Constructors
Span::Span(): 
{
	V = 
}

Span::Span(unsigned int n): N(n) {}

Span::Span(const Span& other): N(other.N) {}

//Copy Assignment Operator
Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		N = other.N;
	}
}

//Destructor
Span::~Span() {}

//Member functions
void	Span::addNumber(int nb)
{
	
}

unsigned int	Span::shortestSpan()
{

}

unsigned int	Span::longestSpan()
{
	
}

void	Span::addRandomNumbers(unsigned int size)
{
	
}

//Exceptions
const char* Span::TooManyElements::what() const throw()
{
	return "Span is full. It's not possible to add any more number\n";
}

const char* Span::TooFewElements::what() const throw()
{
	return "Not enough elements in the Span\n";
}