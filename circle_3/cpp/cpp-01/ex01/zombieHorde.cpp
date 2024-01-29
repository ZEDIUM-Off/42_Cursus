/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:15:54 by  mchenava         #+#    #+#             */
/*   Updated: 2023/12/01 15:22:10 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int n, str name) {
	Zombie*	zombies = new Zombie[n];
	for (int i = 0; i < n; i++) {
		zombies[i].setName(name);
	}
	return zombies;
}
