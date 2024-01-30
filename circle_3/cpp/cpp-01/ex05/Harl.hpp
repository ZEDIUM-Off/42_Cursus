/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchenava <mchenava@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:14:59 by  mchenava         #+#    #+#             */
/*   Updated: 2024/01/30 15:22:30 by mchenava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

enum Level {
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	LEVEL_COUNT
};

class Harl {
	private:
		void debug() { std::cout << "Debug message" << std::endl; }
		void info() { std::cout << "Info message" << std::endl; }
		void warning() { std::cout << "Warning message" << std::endl; }
		void error() { std::cout << "Error message" << std::endl; }

		typedef void (Harl::*FuncPtr)();
		typedef struct LevelStruct {
			std::string levelStr;
			FuncPtr func;
		} lvl;
		LevelStruct levelArray[LEVEL_COUNT];

	public:
		Harl();
		void complain(std::string level);
};

#endif