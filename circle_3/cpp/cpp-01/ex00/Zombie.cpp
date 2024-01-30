/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchenava <mchenava@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:05:06 by  mchenava         #+#    #+#             */
/*   Updated: 2024/01/30 13:21:39 by mchenava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
	std::cout << "Zombie created." << std::endl;
	return ;
}

Zombie::Zombie(str name) : name(name) {
	std::cout << "Zombie " << this->name << " created" << std::endl;
	return ;
}

Zombie::~Zombie() {
	std::cout << "Zombie " << this->name << " is dead" << std::endl;
	return ;
}

void	Zombie::announce() {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}