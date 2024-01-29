/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:01:50 by  mchenava         #+#    #+#             */
/*   Updated: 2023/12/13 15:02:21 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) 
{
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
	std::cout << "ScavTrap " << _name << " has been constructed.\n";
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " has been destructed.\n";
}

void ScavTrap::attack(const std::string &target)
{
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!\n";
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " has entered Gate keeper mode.\n";
}