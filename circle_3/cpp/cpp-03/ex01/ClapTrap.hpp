/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:44:06 by  mchenava         #+#    #+#             */
/*   Updated: 2023/12/13 15:49:38 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>

typedef unsigned int uint;
typedef std::string str;

class ClapTrap
{
	private:
		str		_name;
		uint	_hit_points;
		uint	_energy_points;
		uint	_attack_damage;

	public:
		ClapTrap();
		ClapTrap(str name);
		ClapTrap(const ClapTrap &copy);
		~ClapTrap();
		ClapTrap &operator=(const ClapTrap &copy);

		void	attack(const str &target);
		void	takeDamage(uint amount);
		void	beRepaired(uint amount);
};

#endif