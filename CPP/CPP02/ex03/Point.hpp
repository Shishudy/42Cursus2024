/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 18:03:59 by rafasant          #+#    #+#             */
/*   Updated: 2025/12/29 16:44:46 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point
{
	public:
		Point(void);
		Point(const float, const float);
		Point(const Point &);
		Point &operator=(const Point &);
		Fixed getXValue(void) const;
		Fixed getYValue(void) const;
		~Point(void);
	private:
		Fixed const x;
		Fixed const y;
};

long cross(Point const, Point const, Point const);
bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif