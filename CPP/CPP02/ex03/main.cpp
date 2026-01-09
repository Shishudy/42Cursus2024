/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:54:27 by rafasant          #+#    #+#             */
/*   Updated: 2026/01/09 16:46:30 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{
    Point A(0, 0);
    Point B(10, 0);
    Point C(0, 10);

    std::cout << bsp(A, B, C, Point(2, 2)) << std::endl;
    std::cout << bsp(A, B, C, Point(20, 20)) << std::endl;
    std::cout << bsp(A, B, C, Point(-1, -1)) << std::endl;
    std::cout << bsp(A, B, C, Point(5, 5)) << std::endl;
    std::cout << bsp(A, B, C, Point(0, 10)) << std::endl;
    std::cout << bsp(A, B, C, Point(9.9f, 0.015f)) << std::endl;
    std::cout << bsp(A, B, C, Point(-10.015f, 0.015f)) << std::endl;
    return (0);
}

// static void section(const std::string& title)
// {
//     std::cout << "\n========================================\n";
//     std::cout << title << std::endl;
//     std::cout << "========================================\n";
// }

// static void test(
//     const std::string& label,
//     Point const& a,
//     Point const& b,
//     Point const& c,
//     Point const& p,
//     bool expected)
// {
//     bool result = bsp(a, b, c, p);

//     std::cout << "[TEST] " << label << " -> ";
//     std::cout << (result ? "true" : "false");
//     std::cout << " (expected " << (expected ? "true" : "false") << ")";
//     std::cout << (result == expected ? " ✅" : " ❌");
//     std::cout << std::endl;
// }

// int main(void)
// {
//     /* ========================================================= */
//     section("BASIC TRIANGLE TESTS");
//     /* ========================================================= */

//     Point A(0, 0);
//     Point B(10, 0);
//     Point C(0, 10);

//     test("Inside (2,2)", A, B, C, Point(2, 2), true);
//     test("Outside (20,20)", A, B, C, Point(20, 20), false);
//     test("Outside (-1,-1)", A, B, C, Point(-1, -1), false);

//     /* ========================================================= */
//     section("EDGE CASES (MUST BE FALSE)");
//     /* ========================================================= */

//     test("On edge AB (5,0)", A, B, C, Point(5, 0), false);
//     test("On edge AC (0,5)", A, B, C, Point(0, 5), false);
//     test("On edge BC (5,5)", A, B, C, Point(5, 5), false);

//     test("On vertex A", A, B, C, Point(0, 0), false);
//     test("On vertex B", A, B, C, Point(10, 0), false);
//     test("On vertex C", A, B, C, Point(0, 10), false);

//     /* ========================================================= */
//     section("ORIENTATION TESTS (CW / CCW)");
//     /* ========================================================= */

//     test("CCW order inside", A, B, C, Point(2, 2), true);
//     test("CW order inside", A, C, B, Point(2, 2), true);

//     /* ========================================================= */
//     section("FIXED-POINT PRECISION TESTS");
//     /* ========================================================= */

//     test("Near edge inside (0.1,0.1)", A, B, C, Point(0.1f, 0.1f), true);
//     test("Near edge outside (-0.01,0.01)", A, B, C, Point(-0.01f, 0.01f), false);
//     test("Near hypotenuse inside (4.9,4.9)", A, B, C, Point(4.9f, 4.9f), true);
//     test("Near hypotenuse outside (5.1,5.1)", A, B, C, Point(5.1f, 5.1f), false);

//     /* ========================================================= */
//     section("SKEWED / NON-AXIS-ALIGNED TRIANGLE");
//     /* ========================================================= */

//     Point D(1, 1);
//     Point E(8, 2);
//     Point F(3, 7);

//     test("Inside skewed", D, E, F, Point(4, 3), true);
//     test("Outside skewed", D, E, F, Point(2.9f, 6.9f), false);
//     test("Outside skewed", D, E, F, Point(3.0f, 6.9f), true);
//     test("Outside skewed", D, E, F, Point(6.9f, 6.9f), false);
//     test("On edge skewed", D, E, F, Point(4.5f, 4.5f), true);

//     /* ========================================================= */
//     section("NEGATIVE COORDINATES");
//     /* ========================================================= */

//     Point G(-5, -5);
//     Point H(-1, -6);
//     Point I(-3, -1);

//     test("Inside negative", G, H, I, Point(-3, -4), true);
//     test("Outside negative", G, H, I, Point(0, 0), false);

//     /* ========================================================= */
//     section("DEGENERATE TRIANGLES (MUST BE FALSE)");
//     /* ========================================================= */

//     Point J(0, 0);
//     Point K(5, 5);
//     Point L(10, 10); // Collinear

//     test("Degenerate triangle", J, K, L, Point(5, 5), false);
//     test("Degenerate triangle outside", J, K, L, Point(1, 2), false);

//     /* ========================================================= */
//     section("LARGE COORDINATES");
//     /* ========================================================= */

//     Point M(10000, 10000);
//     Point N(20000, 10000);
//     Point O(15000, 20000);

//     test("Inside large", M, N, O, Point(15000, 15000), true);
//     test("Outside large", M, N, O, Point(30000, 30000), false);

//     /* ========================================================= */
//     section("ALL BSP TESTS COMPLETED");
//     /* ========================================================= */

//     return 0;
// }