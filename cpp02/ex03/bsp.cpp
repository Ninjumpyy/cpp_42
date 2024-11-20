/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:10:20 by tle-moel          #+#    #+#             */
/*   Updated: 2024/11/20 13:16:15 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

float	cross_product(const Point &v1, const Point &v2)
{
	return (v1.getX().toFloat() * v2.getY().toFloat() - v1.getY().toFloat() * v2.getX().toFloat());
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	const Point Vab(b.getX().toFloat() - a.getX().toFloat(), b.getY().toFloat() - a.getY().toFloat());
	const Point Vap(point.getX().toFloat() - a.getX().toFloat(), point.getY().toFloat() - a.getY().toFloat());
	const Point Vbc(c.getX().toFloat() - b.getX().toFloat(), c.getY().toFloat() - b.getY().toFloat());
	const Point Vbp(point.getX().toFloat() - b.getX().toFloat(), point.getY().toFloat() - b.getY().toFloat());
	const Point Vca(a.getX().toFloat() - c.getX().toFloat(), a.getY().toFloat() - c.getY().toFloat());
	const Point Vcp(point.getX().toFloat() - c.getX().toFloat(), point.getY().toFloat() - c.getY().toFloat());
	
	float	cross1 = cross_product(Vab, Vap);
	float	cross2 = cross_product(Vbc, Vbp);
	float	cross3 = cross_product(Vca, Vcp);

	if (cross1 > 0 && cross2 > 0 && cross3 > 0)
		return (true);
	if (cross1 < 0 && cross2 < 0 && cross3 < 0)
		return (true);
	else
		return (false);
}