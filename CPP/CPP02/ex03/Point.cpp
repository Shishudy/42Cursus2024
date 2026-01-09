/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 18:05:20 by rafasant          #+#    #+#             */
/*   Updated: 2026/01/09 16:37:08 by rafasant         ###   ########.fr       */
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

Point::~Point(void)
{

}