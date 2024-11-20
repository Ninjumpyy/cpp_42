/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:03:37 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/20 10:53:30 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

// Constructor
Fixed::Fixed()
{
	_value = 0;
}

Fixed::Fixed(const int value)
{
	_value = value << _bits;
}

Fixed::Fixed(const float value)
{
	_value = static_cast<int>(roundf(value * 256));
}

// Copy Constructor
Fixed::Fixed(const Fixed &other) : _value(other._value) {}

// Copy Assignment Operator
Fixed& Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	{
		_value = other._value;
	}
	return (*this);
}

// Destructor
Fixed::~Fixed() {}

// Comparison operators
bool Fixed::operator>(const Fixed &other) const
{
	return (_value > other._value);
}

bool Fixed::operator<(const Fixed &other) const
{
	return (_value < other._value);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (_value >= other._value);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (_value <= other._value);
}

bool Fixed::operator==(const Fixed &other) const
{
	return (_value == other._value);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (_value != other._value);
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed &other) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other) const
{
	if (other._value == 0)
	{
		std::cerr << "Error: Division by zero\n";
		return (Fixed(0));
	}
	else
		return (Fixed(this->toFloat() / other.toFloat()));
}

// Decrement and Increment operators

// Pre-increment : ++x
Fixed &Fixed::operator++()
{
	_value++;
	return (*this);
}

// Post-increment : x++
Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	_value++;
	return (temp);
}

// Pre-increment : --x
Fixed &Fixed::operator--()
{
	_value--;
	return (*this);
}

// Post-increment : x--
Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	_value--;
	return (temp);
}

// Member functions
int	Fixed::getRawBits() const
{
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	_value = raw;
}

float	Fixed::toFloat(void) const
{
	return (_value / 256.0f);
}

int	Fixed::toInt(void) const
{
	return (_value >> 8);
}

Fixed &Fixed::min(Fixed &obj1, Fixed &obj2)
{
	if (obj1 <= obj2)
		return (obj1);
	else
		return (obj2);
}

const Fixed &Fixed::min(const Fixed &obj1, const Fixed &obj2)
{
	if (obj1 <= obj2)
		return (obj1);
	else
		return (obj2);
}

Fixed &Fixed::max(Fixed &obj1, Fixed &obj2)
{
	if (obj1 >= obj2)
		return (obj1);
	else
		return (obj2);
}

const Fixed &Fixed::max(const Fixed &obj1, const Fixed &obj2)
{
	if (obj1 >= obj2)
		return (obj1);
	else
		return (obj2);
}

// Friend function for << operator
std::ostream& operator<<(std::ostream &os, const Fixed &other)
{
	os << other.toFloat();
	return (os);
}
