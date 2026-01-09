/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 16:36:51 by rafasant          #+#    #+#             */
/*   Updated: 2026/01/09 16:41:48 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static long cross(Point const p1, Point const p2, Point const point)
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