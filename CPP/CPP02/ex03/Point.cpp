/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 18:05:20 by rafasant          #+#    #+#             */
/*   Updated: 2025/12/29 16:47:42 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : x(), y()
{

}

Point::Point(const float xVal, const float yVal) : x(xVal), y(yVal)
{

}

Point::Point(Point const& point) : x(point.x), y(point.y)
{
	
}

Point& Point::operator=(Point const& point)
{
    (void)point;
    return *this;
}

Fixed Point::getXValue(void) const
{
	return (this->x);
}

Fixed Point::getYValue(void) const
{
	return (this->y);
}

long cross(Point const p1, Point const p2, Point const point)
{
	long x1;
	long y1;
	long x2;
	long y2;
	
	x1 = p2.getXValue().getRawBits() - p1.getXValue().getRawBits();
	y1 = p2.getYValue().getRawBits() - p1.getYValue().getRawBits();
	x2 = point.getXValue().getRawBits() - p1.getXValue().getRawBits();
	y2 = point.getYValue().getRawBits() - p1.getYValue().getRawBits();
	return (x1 * y2 - y1 * x2);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	long abp;
	long bcp;
	long cap;

	abp = cross(a, b, point);
	bcp = cross(b, c, point);
	cap = cross(c, a, point);
	if ((abp < 0 && bcp < 0 && cap < 0) || (abp > 0 && bcp > 0 && cap > 0))
	{
		return (true);
	}
	return (false);
}

Point::~Point(void)
{

}