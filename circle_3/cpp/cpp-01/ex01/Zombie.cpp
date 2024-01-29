/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:05:06 by  mchenava         #+#    #+#             */
/*   Updated: 2023/12/01 15:27:44 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
	return ;
}

Zombie::Zombie(str name) : name(name) {
	return ;
}

Zombie::~Zombie() {
	std::cout << "Zombie " << this->name << " is dead" << std::endl;
	return ;
}

void	Zombie::announce() {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(str name) {
	this->name = name;
}

