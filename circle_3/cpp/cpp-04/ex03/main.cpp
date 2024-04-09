/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchenava <mchenava@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:18:24 by mchenava          #+#    #+#             */
/*   Updated: 2024/04/09 13:34:36 by mchenava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main() {
    std::cout << "----CREATING MATSRC------" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    std::cout << "----CREATING CHARACTER(me)------" << std::endl;
    ICharacter* me = new Character("me");

    std::cout << "----CREATING MATERIA------" << std::endl;
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    std::cout << "----CREATING CHARACTER(bob)------" << std::endl;
    ICharacter* bob = new Character("bob");

    std::cout << "----USING MATERIA------" << std::endl;
    me->use(0, *bob);
    me->use(1, *bob);

    // Test unequip
    std::cout << "----TESTING UNEQUIP------" << std::endl;
    me->unequip(1); // Test unequip without deleting
    me->use(0, *bob); // Should do nothing

    // Test equip after unequip
    std::cout << "----TESTING EQUIP AFTER UNEQUIP------" << std::endl;
    me->equip(tmp); // Re-equip the unequipped materia
    me->use(0, *bob); // Should work now

    // Test over equip
    std::cout << "----TESTING OVER EQUIP------" << std::endl;
    me->equip(new Ice());
    me->equip(new Ice());
    // me->equip(new Ice()); // Should not equip this one, inventory is full

    std::cout << "----DELETING CHARACTERS------" << std::endl;
    std::cout << "----DELETING BOB------" << std::endl;
	delete bob;
	std::cout << "----DELETING ME------" << std::endl;
    delete me;

    std::cout << "----DELETING MATSRC------" << std::endl;
    delete src;

    return 0;
}
