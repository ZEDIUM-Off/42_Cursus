/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:52:58 by  mchenava         #+#    #+#             */
/*   Updated: 2023/12/13 15:03:04 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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

    return 0;
}