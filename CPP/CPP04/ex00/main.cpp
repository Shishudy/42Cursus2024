/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:54:27 by rafasant          #+#    #+#             */
/*   Updated: 2026/01/14 15:23:11 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    delete meta;
    delete j;
    delete i;
    return 0;
}

// int main(void)
// {
//     std::cout << "--- Correct Polymorphism ---" << std::endl;
//     const Animal* animal = new Animal();
//     const Animal* dog = new Dog();
//     const Animal* cat = new Cat();

//     std::cout << animal->getType() << " " << std::endl;
//     std::cout << dog->getType() << " " << std::endl;
//     std::cout << cat->getType() << " " << std::endl;
//     animal->makeSound();
//     dog->makeSound();
//     cat->makeSound();
//     delete animal;
//     delete dog;
//     delete cat;

//     std::cout << "--- Wrong (Non-Polymorphic) Example ---" << std::endl;
//     const WrongAnimal* wrongAnimal = new WrongAnimal();
//     const WrongAnimal* wrongCat = new WrongCat();

//     std::cout << wrongAnimal->getType() << " " << std::endl;
//     std::cout << wrongCat->getType() << " " << std::endl;
//     wrongAnimal->makeSound();
//     wrongCat->makeSound();
//     delete wrongAnimal;
//     delete wrongCat;

//     std::cout << "--- Direct WrongCat instance ---" << std::endl;
//     WrongCat directWrongCat;
//     directWrongCat.makeSound();
//     return (0);
// }
