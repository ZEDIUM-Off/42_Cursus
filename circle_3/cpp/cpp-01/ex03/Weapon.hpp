/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchenava <mchenava@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:11:07 by  mchenava         #+#    #+#             */
/*   Updated: 2024/01/30 13:40:18 by mchenava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

typedef std::string str;


class Weapon
{
	private:
		str type;

	public:
					Weapon();
					Weapon(str type);
					~Weapon();
		str const 	&getType();
		void 		setType(str type);
};

#endif