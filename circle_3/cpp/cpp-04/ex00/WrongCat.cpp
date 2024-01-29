/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:13:36 by  mchenava         #+#    #+#             */
/*   Updated: 2023/12/13 17:13:41 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
}

WrongCat::~WrongCat() {}

void WrongCat::makeSound() const
{
	std::cout << "Wrong cat sound" << std::endl;
}