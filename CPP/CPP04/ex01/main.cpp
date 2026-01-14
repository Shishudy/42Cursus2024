/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:54:27 by rafasant          #+#    #+#             */
/*   Updated: 2026/01/14 15:20:43 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << dog->getType() << " " << std::endl;
    std::cout << cat->getType() << " " << std::endl;
    dog->makeSound();
    cat->makeSound();
    delete dog;
    delete cat;
    return (0);
}

// int main(void)
// {
//     std::cout << "\n-- Array tests --" << std::endl;
//     const int N = 10;
//     Animal* animals[N];
//     for (int i = 0; i < N; ++i)
//     {
//         if (i < N / 2)
//             animals[i] = new Dog();
//         else
//             animals[i] = new Cat();
//     }

//     std::cout << "\n-- Deleting animals as Animal* --" << std::endl;
//     for (int i = 0; i < N; ++i)
//         delete animals[i];

//     std::cout << "\n-- Deep copy tests --" << std::endl;
//     std::cout << "[Dog deep copy]" << std::endl;
//     Dog dogOriginal;
//     dogOriginal.setIdea(0, "Original idea");
//     Dog dogCopy(dogOriginal);
//     dogOriginal.setIdea(0, "Altered idea");
//     std::cout << "\nOriginal's idea[0]: " << dogOriginal.getIdea(0) << std::endl;
//     std::cout << "Copy's idea[0]: " << dogCopy.getIdea(0) << std::endl;
//     std::cout << "\n[Cat deep copy]" << std::endl;
//     Cat catOriginal;
//     catOriginal.setIdea(0, "Original idea");
//     Cat catCopy;
//     catCopy = catOriginal;
//     catOriginal.setIdea(0, "Altered idea");
//     std::cout << "\nOriginal's idea[0]: " << catOriginal.getIdea(0) << std::endl;
//     std::cout << "Copy's idea[0]: " << catCopy.getIdea(0) << "\n" << std::endl;
//     return (0);
// }
