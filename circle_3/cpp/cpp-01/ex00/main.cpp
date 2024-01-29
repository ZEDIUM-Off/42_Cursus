/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:05:17 by  mchenava         #+#    #+#             */
/*   Updated: 2023/12/01 15:00:28 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	Zombie*	zombie = newZombie("Zombie1");
	zombie->announce();
	randomChump("Zombie2");
	delete zombie;
	return 0;
}