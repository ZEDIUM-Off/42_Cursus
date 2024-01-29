/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:05:17 by  mchenava         #+#    #+#             */
/*   Updated: 2023/12/01 15:28:20 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	Zombie*	zombie = zombieHorde(5, "Zombie");
	for (int i = 0; i < 5; i++)
		zombie[i].announce();
	delete[] zombie;
	return 0;
}