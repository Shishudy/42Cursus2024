/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:53:37 by rafasant          #+#    #+#             */
/*   Updated: 2025/12/25 19:01:26 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const int);
		Fixed(const float);
		Fixed(const Fixed &);
		Fixed &operator=(const Fixed &);
		bool operator>(const Fixed &) const;
		bool operator<(const Fixed &) const;
		bool operator>=(const Fixed &) const;
		bool operator<=(const Fixed &) const;
		bool operator==(const Fixed &) const;
		bool operator!=(const Fixed &) const;
		Fixed operator+(const Fixed &) const;
		Fixed operator-(const Fixed &) const;
		Fixed operator*(const Fixed &) const;
		Fixed operator/(const Fixed &) const;
		Fixed &operator++(void);
		Fixed &operator--(void);
		Fixed operator++(int);
		Fixed operator--(int);
		static Fixed &min(Fixed &, Fixed &);
		const static Fixed &min(const Fixed &, const Fixed &);
		static Fixed &max(Fixed &, Fixed &);
		const static Fixed &max(const Fixed &, const Fixed &);
		int getRawBits(void) const;
		void setRawBits(int const);
		float toFloat(void) const;
		int toInt(void) const;
		~Fixed(void);
	private:
		int	_raw;
		static const int _fractionalBits = 8;
};

std::ostream& operator<<(std::ostream&, const Fixed&);

#endif