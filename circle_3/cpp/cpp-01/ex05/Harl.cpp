/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchenava <mchenava@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:16:01 by  mchenava         #+#    #+#             */
/*   Updated: 2024/01/23 14:36:32 by mchenava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() 
{
	funcMap["DEBUG"] = &Harl::debug;
	funcMap["INFO"] = &Harl::info;
	funcMap["WARNING"] = &Harl::warning;
	funcMap["ERROR"] = &Harl::error;
}

void Harl::complain(std::string level)
{
	if (funcMap.find(level) != funcMap.end())
		(this->*funcMap[level])();
	else
		std::cerr << "Invalid level: " << level << std::endl;
}
