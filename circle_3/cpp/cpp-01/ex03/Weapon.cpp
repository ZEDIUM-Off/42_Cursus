/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:10:35 by  mchenava         #+#    #+#             */
/*   Updated: 2023/12/06 15:14:14 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
	this->type = "default";
}

Weapon::Weapon(str type)
{
	this->type = type;
}

Weapon::~Weapon()
{
}

str const &Weapon::getType()
{
	return this->type;
}

void Weapon::setType(str type)
{
	this->type = type;
}