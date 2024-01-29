/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:11:14 by  mchenava         #+#    #+#             */
/*   Updated: 2023/12/13 17:11:20 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {}

WrongAnimal::~WrongAnimal() {}

void WrongAnimal::makeSound() const
{
	std::cout << "Wrong animal sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return type;
}