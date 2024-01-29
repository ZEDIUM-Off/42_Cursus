/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:52:58 by  mchenava         #+#    #+#             */
/*   Updated: 2023/12/13 14:53:22 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap claptrap("Clappy");

    claptrap.attack("enemy");
    claptrap.takeDamage(5);
    claptrap.beRepaired(5);

    return 0;
}