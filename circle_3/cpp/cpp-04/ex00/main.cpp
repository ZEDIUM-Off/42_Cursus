/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:05:13 by  mchenava         #+#    #+#             */
/*   Updated: 2024/04/08 12:46:22 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongI = new WrongCat();

    std::cout << "-------------------------------" << std::endl;
    std::cout << meta->getType() << " " << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << wrongMeta->getType() << " " << std::endl;
    std::cout << wrongI->getType() << " " << std::endl;
    std::cout << "-------------------------------" << std::endl;
    meta->makeSound();
    i->makeSound();
    j->makeSound();

    std::cout << "-------------------------------" << std::endl;
    std::cout << wrongI->getType() << " " << std::endl;
    wrongMeta->makeSound();
    wrongI->makeSound();
    std::cout << "-------------------------------" << std::endl;

    delete meta;
    delete j;
    delete i;
    delete wrongMeta;
    delete wrongI;

    return 0;
}