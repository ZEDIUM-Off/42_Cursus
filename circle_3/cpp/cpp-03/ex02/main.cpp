/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:52:58 by  mchenava         #+#    #+#             */
/*   Updated: 2023/12/13 15:11:30 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ClapTrap claptrap("Clappy");

    claptrap.attack("enemy");
    claptrap.takeDamage(5);
    claptrap.beRepaired(5);

    ScavTrap scavtrap("Scavvy");

    scavtrap.attack("enemy");
    scavtrap.takeDamage(5);
    scavtrap.beRepaired(5);
    scavtrap.guardGate();

    FragTrap fragtrap("Fraggy");

    fragtrap.attack("enemy");
    fragtrap.takeDamage(5);
    fragtrap.beRepaired(5);
    fragtrap.highFivesGuys();

    return 0;

    return 0;
}