/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:05:15 by  mchenava         #+#    #+#             */
/*   Updated: 2023/12/01 14:14:43 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "Zombie.hpp"

Zombie*	newZombie(str name) {
	Zombie*	zombie = new Zombie(name);
	return zombie;
}