/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:05:50 by thomas            #+#    #+#             */
/*   Updated: 2024/12/18 16:33:37 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

//Constructors
Span::Span()
{
	_container.reserve(2);
}

Span::Span(unsigned int N)
{
	_container.reserve(N);
}

Span::Span(const Span& other)
{
	_container.reserve(other._container.capacity());
	_container = other._container;
}

//Copy Assignment Operator
Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_container.reserve(other._container.capacity());
		_container = other._container;
	}
	return (*this);
}

//Destructor
Span::~Span() {}

//Member functions
void	Span::addNumber(int nb)
{
	if (_container.size() >= _container.capacity())
		throw TooManyElements();	
	_container.push_back(nb);
}

unsigned int	Span::shortestSpan()
{	
	if (_container.size() < 2)
		throw TooFewElements();
	std::vector<int> sorted = _container;
	sort(sorted.begin(), sorted.end());
	unsigned int shortest = UINT_MAX;
	for (size_t i = 0; i < sorted.size() - 1; i++)
	{
		unsigned int diff = sorted[i + 1] - sorted[i];
		if (diff < shortest)
			shortest = diff;
	}
	return shortest;
}

unsigned int	Span::longestSpan()
{
	if (_container.size() < 2)
		throw TooFewElements();
	return  (*std::max_element(_container.begin(), _container.end()) - *std::min_element(_container.begin(), _container.end()));
	
}

void	Span::addRange(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	if (std::distance(start, end) + _container.size() > _container.capacity())
		throw TooManyElements();
	_container.insert(_container.end(), start, end);
}

//Exceptions
const char* Span::TooManyElements::what() const throw()
{
	return "Span is full. It's not possible to add any more number";
}

const char* Span::TooFewElements::what() const throw()
{
	return "Not enough elements in the Span";
}
