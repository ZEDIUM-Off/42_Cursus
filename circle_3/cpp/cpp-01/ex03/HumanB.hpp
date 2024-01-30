/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchenava <mchenava@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:16:29 by  mchenava         #+#    #+#             */
/*   Updated: 2024/01/30 13:39:36 by mchenava         ###   ########.fr       */
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
		str 	name;
		Weapon 	*weapon;

	public:
				HumanB(str name);
				~HumanB();
		void 	attack();
		void 	setWeapon(Weapon &weapon);
};

#endif