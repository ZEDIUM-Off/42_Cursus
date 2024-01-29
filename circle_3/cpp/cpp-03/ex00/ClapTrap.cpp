/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:50:02 by  mchenava         #+#    #+#             */
/*   Updated: 2023/12/13 15:07:25 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "ClapTrap " << _name << " has been created." << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " has been destroyed." << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (_energy_points > 0)
	{
		_energy_points--;
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " has no energy points left to attack." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit_points > amount)
	{
		_hit_points -= amount;
		std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
	}
	else
	{
		_hit_points = 0;
		std::cout << "ClapTrap " << _name << " has been destroyed." << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energy_points > 0)
	{
		_energy_points--;
		_hit_points += amount;
		std::cout << "ClapTrap " << _name << " is repaired for " << amount << " hit points!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " has no energy points left to be repaired." << std::endl;
}