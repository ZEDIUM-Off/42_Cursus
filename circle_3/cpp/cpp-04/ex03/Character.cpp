/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchenava <mchenava@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:58:31 by mchenava          #+#    #+#             */
/*   Updated: 2024/04/09 13:33:38 by mchenava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character(std::string const & name) : _name(name) {
    std::cout << "Character constructor called" << std::endl;
	for (int i = 0; i < 4; ++i) {
        this->_inventory[i] = NULL;
    }
}

Character::Character(Character const & other) : _name(other._name) {
    std::cout << "Character copy constructor called" << std::endl;
	*this = other;
}

Character & Character::operator=(Character const & other) {
    if (this != &other) {
        this->_name = other._name;
        for (int i = 0; i < 4; ++i) {
			if (this->_inventory[i])
				delete this->_inventory[i];
			if (other._inventory[i])
				this->_inventory[i] = other._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
        }
    }
    return *this;
}

Character::~Character() {
    std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; ++i) {
		if (this->_inventory[i])
			delete this->_inventory[i];
    }
}

std::string const & Character::getName() const {
    return this->_name;
}

void	Character::equip(AMateria* m) {
	for (int i = 0; i < 4; ++i) {
		if (this->_inventory[i] == NULL) {
			this->_inventory[i] = m;
			return;
		}
	}
}

void	Character::unequip(int idx) {
	if (idx < 0 || idx > 3)
		return;
	this->_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 3)
		return;
	if (this->_inventory[idx])
		this->_inventory[idx]->use(target);
}
