/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 12:52:30 by  mchenava         #+#    #+#             */
/*   Updated: 2024/04/08 12:53:32 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain {
	public:
			std::string ideas[100];

			Brain();
			Brain(const Brain& other);
			Brain& operator=(const Brain& other);
			~Brain();
};

#endif