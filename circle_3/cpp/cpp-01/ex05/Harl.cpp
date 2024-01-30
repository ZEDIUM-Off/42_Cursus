/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchenava <mchenava@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:16:01 by  mchenava         #+#    #+#             */
/*   Updated: 2024/01/30 15:22:49 by mchenava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() 
{
	levelArray[DEBUG] = (lvl){"DEBUG", &Harl::debug};
	levelArray[INFO] = (lvl){"INFO", &Harl::info};
	levelArray[WARNING] = (lvl){"WARNING", &Harl::warning};
	levelArray[ERROR] = (lvl){"ERROR", &Harl::error};
}

void Harl::complain(std::string level)
{
	for (int i = 0; i < LEVEL_COUNT; i++)
	{
		if (levelArray[i].levelStr == level)
		{
			(this->*levelArray[i].func)();
			return;
		}
	}
	std::cerr << "Invalid level: " << level << std::endl;
}
