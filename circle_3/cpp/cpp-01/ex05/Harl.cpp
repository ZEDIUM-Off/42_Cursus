/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchenava <mchenava@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:16:01 by  mchenava         #+#    #+#             */
/*   Updated: 2024/01/30 13:34:53 by mchenava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() 
{
	funcArray[DEBUG] = &Harl::debug;
	funcArray[INFO] = &Harl::info;
	funcArray[WARNING] = &Harl::warning;
	funcArray[ERROR] = &Harl::error;
}

void Harl::complain(Level level)
{
	if (level >= 0 && level < LEVEL_COUNT)
		(this->*funcArray[level])();
	else
		std::cerr << "Invalid level: " << level << std::endl;
}
