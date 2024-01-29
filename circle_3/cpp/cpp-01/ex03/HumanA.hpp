/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:14:47 by  mchenava         #+#    #+#             */
/*   Updated: 2023/12/06 15:20:07 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#	include <string>
# include <iostream>

#	include "Weapon.hpp"

typedef std::string str;

class HumanA
{
	private:
		str name;
		Weapon &weapon;

	public:
		HumanA(str name, Weapon &weapon);
		~HumanA();
		void attack();
};

#endif