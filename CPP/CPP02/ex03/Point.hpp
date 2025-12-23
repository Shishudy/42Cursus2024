/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 18:03:59 by rafasant          #+#    #+#             */
/*   Updated: 2025/12/23 18:07:48 by rafasant         ###   ########.fr       */
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
		~Point(void);
	private:
		Fixed const x;
		Fixed const y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif