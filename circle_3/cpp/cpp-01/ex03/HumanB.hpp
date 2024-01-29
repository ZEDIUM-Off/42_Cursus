/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:16:29 by  mchenava         #+#    #+#             */
/*   Updated: 2023/12/06 15:20:07 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#	include <string>
# include <iostream>

#	include "Weapon.hpp"

typedef std::string str;

class HumanB
{
	private:
		str name;
		Weapon *weapon;

	public:
		HumanB(str name);
		~HumanB();
		void attack();
		void setWeapon(Weapon &weapon);
};

#endif