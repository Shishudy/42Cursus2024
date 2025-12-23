/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:54:27 by rafasant          #+#    #+#             */
/*   Updated: 2025/12/23 18:01:48 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return (0);
}

// static void section(const std::string& title)
// {
//     std::cout << "\n==============================\n";
//     std::cout << title << std::endl;
//     std::cout << "==============================\n";
// }

// int main(void)
// {
//     section("EX00: Orthodox Canonical Form");
//     {
//         Fixed a;
//         Fixed b(a);
//         Fixed c;

//         c = b;

//         std::cout << "[RESULT] a raw = " << a.getRawBits() << std::endl;
//         std::cout << "[RESULT] b raw = " << b.getRawBits() << std::endl;
//         std::cout << "[RESULT] c raw = " << c.getRawBits() << std::endl;
//     }
//     {
//         Fixed self;
//         self = self;
//         std::cout << "[RESULT] self-assign raw = " << self.getRawBits() << std::endl;
//     }

//     section("EX01: Constructors & Conversions");
//     {
//         Fixed a;
//         Fixed const b(10);
//         Fixed const c(42.42f);
//         Fixed const d(b);

//         a = Fixed(1234.4321f);

//         std::cout << "[RESULT] a is " << a << std::endl;
//         std::cout << "[RESULT] b is " << b << std::endl;
//         std::cout << "[RESULT] c is " << c << std::endl;
//         std::cout << "[RESULT] d is " << d << std::endl;

//         std::cout << "[RESULT] a as int = " << a.toInt() << std::endl;
//         std::cout << "[RESULT] b as int = " << b.toInt() << std::endl;
//         std::cout << "[RESULT] c as int = " << c.toInt() << std::endl;
//         std::cout << "[RESULT] d as int = " << d.toInt() << std::endl;
//     }
//     {
//         Fixed tiny(0.001f);
//         std::cout << "[RESULT] 0.001f = " << tiny << std::endl;

//         Fixed neg(-42.42f);
//         std::cout << "[RESULT] negative = " << neg << std::endl;
//         std::cout << "[RESULT] negative int = " << neg.toInt() << std::endl;
//     }

//     section("EX02: Comparison Operators");
//     {
//         Fixed a(5);
//         Fixed b(10);

//         std::cout << "[RESULT] a < b  = " << (a < b) << std::endl;
//         std::cout << "[RESULT] a > b  = " << (a > b) << std::endl;
//         std::cout << "[RESULT] a <= b = " << (a <= b) << std::endl;
//         std::cout << "[RESULT] a >= b = " << (a >= b) << std::endl;
//         std::cout << "[RESULT] a == b = " << (a == b) << std::endl;
//         std::cout << "[RESULT] a != b = " << (a != b) << std::endl;
//     }
//     {
//         Fixed a(5);
//         Fixed b(5.0f);
//         std::cout << "[RESULT] a == b (int vs float) = " << (a == b) << std::endl;

//         Fixed x(1.0f);
//         Fixed y = x;
//         y++;
//         std::cout << "[RESULT] x < y after increment = " << (x < y) << std::endl;
//     }

//     section("EX02: Arithmetic Operators");
//     {
//         Fixed a(5.05f);
//         Fixed b(2);

//         Fixed sum  = a + b;
//         Fixed diff = a - b;
//         Fixed prod = a * b;
//         Fixed quot = a / b;

//         std::cout << "[RESULT] a + b = " << sum << std::endl;
//         std::cout << "[RESULT] a - b = " << diff << std::endl;
//         std::cout << "[RESULT] a * b = " << prod << std::endl;
//         std::cout << "[RESULT] a / b = " << quot << std::endl;
//     }
//     {
//         Fixed a(42.42f);
//         Fixed zero(0);
//         std::cout << "[RESULT] a * 0 = " << (a * zero) << std::endl;
//     }
//     {
//         Fixed a(7.25f);
//         Fixed one(1);
//         std::cout << "[RESULT] a / 1 = " << (a / one) << std::endl;
//     }
//     {
//         Fixed a(1.5f);
//         Fixed b(2.25f);
//         Fixed c(3);

//         Fixed r = a + b * c - Fixed(1);
//         std::cout << "[RESULT] chained expression = " << r << std::endl;
//     }

//     section("EX02: Increment / Decrement");
//     {
//         Fixed a;

//         std::cout << "[RESULT] a        = " << a << std::endl;
//         std::cout << "[RESULT] ++a      = " << ++a << std::endl;
//         std::cout << "[RESULT] a        = " << a << std::endl;
//         std::cout << "[RESULT] a++      = " << a++ << std::endl;
//         std::cout << "[RESULT] a        = " << a << std::endl;
//         std::cout << "[RESULT] --a      = " << --a << std::endl;
//         std::cout << "[RESULT] a--      = " << a-- << std::endl;
//         std::cout << "[RESULT] a        = " << a << std::endl;
//     }
//     {
//         Fixed a;
//         for (int i = 0; i < 10; i++)
//             ++a;

//         std::cout << "[RESULT] a after 10 pre-increments = " << a << std::endl;
//     }

//     section("EX02: min / max");
//     {
//         Fixed a(1.5f);
//         Fixed b(2.5f);

//         std::cout << "[RESULT] min(a,b) = " << Fixed::min(a, b) << std::endl;
//         std::cout << "[RESULT] max(a,b) = " << Fixed::max(a, b) << std::endl;
//     }
//     {
//         const Fixed c(3.5f);
//         const Fixed d(4.5f);

//         std::cout << "[RESULT] min(c,d) = " << Fixed::min(c, d) << std::endl;
//         std::cout << "[RESULT] max(c,d) = " << Fixed::max(c, d) << std::endl;
//     }
//     {
//         Fixed a(3.14f);
//         std::cout << "[RESULT] min(a,a) = " << Fixed::min(a, a) << std::endl;
//     }
//     {
//         Fixed a(-1.5f);
//         Fixed b(2.0f);

//         std::cout << "[RESULT] min(neg,pos) = " << Fixed::min(a, b) << std::endl;
//         std::cout << "[RESULT] max(neg,pos) = " << Fixed::max(a, b) << std::endl;
//     }

//     section("ALL TESTS COMPLETED");
//     return 0;
// }