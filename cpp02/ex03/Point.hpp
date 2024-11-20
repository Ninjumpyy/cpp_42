/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:10:26 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/20 12:44:27 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		const Fixed x;
		const Fixed y;
		
	public:
		//Constructor
		Point();
		Point(const float a, const float b);

		//Copy Constructor
		Point(const Point &other);

		//Copy Assignment Operator deleted
		Point &operator=(const Point &other);

		//Destructor
		~Point();

		//Member Functions
		const Fixed getX() const;
		const Fixed getY() const;
};

#endif