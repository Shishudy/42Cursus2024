/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:54:27 by rafasant          #+#    #+#             */
/*   Updated: 2026/01/01 19:45:50 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	int			i;
	DiamondTrap	dt1("DT1");
	DiamondTrap	dt2("DT2");

	dt1.showHitPoints();
	dt1.showEnergy();
	dt1.showAttackDamage();
	dt2.showHitPoints();
	dt2.showEnergy();
	dt2.showAttackDamage();
	std::cout << std::endl;
	i = 0;
	while (i < 3)
	{
		dt1.attack("DT2");
		dt2.takeDamage(30);
		i++;
	}
	std::cout << std::endl;
	dt2.beRepaired(20);
	dt2.attack("DT1");
	dt1.takeDamage(30);
	std::cout << std::endl;
	dt1.guardGate();
	dt1.highFivesGuys();
	std::cout << std::endl;
	dt1.whoAmI();
	std::cout << std::endl;
	DiamondTrap dt3(dt1);
	dt3.whoAmI();
	std::cout << std::endl;
	DiamondTrap dt4("TEMP");
	dt4 = dt1;
	dt4.whoAmI();
	return 0;
}

// void test_and_show(const std::string& scenario, DiamondTrap &dt)
// {
//     std::cout << "\n--- " << scenario << " ---\n";
//     dt.showHitPoints();
//     dt.showEnergy();
//     dt.showAttackDamage();
//     dt.whoAmI();
// }

// int main(void)
// {
//     // 1. Create pristine objects
//     DiamondTrap dtA("Alpha");
//     DiamondTrap dtB("Beta");

//     test_and_show("Initial Alpha", dtA);
//     test_and_show("Initial Beta", dtB);

//     // 2. Mutate Alpha
//     dtA.attack("Beta");    // costs 1 energy
//     dtA.takeDamage(30);    // loses 30 HP
//     dtA.beRepaired(20);    // repairs 20 HP (costs 1 energy)

//     test_and_show("Mutated Alpha", dtA);

//     // 3. Copy construct from original Beta (untouched)
//     DiamondTrap dtCopy1(dtB);
//     test_and_show("Copy of untouched Beta (copy ctor)", dtCopy1);

//     // 4. Copy construct from mutated Alpha
//     DiamondTrap dtCopy2(dtA);
//     test_and_show("Copy of mutated Alpha (copy ctor)", dtCopy2);

//     // 5. Assignment: Assign mutated Alpha into untouched Beta
//     DiamondTrap dtBclone("Temp");
//     dtBclone = dtA;
//     test_and_show("dtBclone = mutated Alpha", dtBclone);

//     // 6. Mutate the copy and show originals are unaffected (deep copy)
//     dtCopy2.attack("Test");
//     dtCopy2.takeDamage(100); // Reduce HP to 0
//     test_and_show("Mutated Copy of Alpha", dtCopy2);

//     // Prove originals are not altered
//     test_and_show("Check Alpha after copy mutated", dtA);

//     // 7. Assign original untouched Beta into dtCopy2 (which was mutated)
//     dtCopy2 = dtB;
//     test_and_show("dtCopy2 = untouched Beta (was previously mutated copy of Alpha)", dtCopy2);

//     // Optional: Guard Gate and High Fives
//     dtA.guardGate();
//     dtA.highFivesGuys();

//     return 0;
// }