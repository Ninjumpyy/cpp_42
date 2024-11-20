/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:11:50 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/20 13:18:13 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>
#include <string>

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
	Point const a(0, 0);
	Point const b(4,0);
	Point const c(0,4);
	Point const p(2,2);

	std::cout << "Example: A(0,0) B(4,0) C(0,4)\nLet's find if point P(2,2) is inside the triangle ABC...\n";
	if (bsp(a, b, c, p))
		std::cout << "P is inside the triangle!\n";
	else
		std::cout << "P is not inside the triangle!\n";

	return (0);
}