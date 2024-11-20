/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:10:24 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/20 13:14:15 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

//Constructor
Point::Point() : x(0), y(0) {}

Point::Point(const float a, const float b) : x(a), y(b) {}

//Copy Constructor
Point::Point(const Point &other) : x(other.x), y(other.y) {}

//Copy Assignment Operator
//Doing nothing here, x and y are constant, they can't be reassign
Point &Point::operator=(const Point &other)
{
	(void)other;
	return (*this);
}

//Destructor
Point::~Point() {}

//Member Functions
const Fixed Point::getX() const
{
	return (x);
}

const Fixed Point::getY() const
{
	return (y);
}
