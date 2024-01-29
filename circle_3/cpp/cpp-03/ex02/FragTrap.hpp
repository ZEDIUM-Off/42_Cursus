/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:10:03 by  mchenava         #+#    #+#             */
/*   Updated: 2023/12/13 15:13:19 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:
		str				_name;
		uint			_hit_points;
		uint			_energy_points;
		uint			_attack_damage;

	public:
    FragTrap(std::string name);
    ~FragTrap();

    void attack(const std::string &target);
    void highFivesGuys();
};

#endif