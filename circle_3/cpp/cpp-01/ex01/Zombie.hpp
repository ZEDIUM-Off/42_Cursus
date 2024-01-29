/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchenava <mchenava@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:05:09 by  mchenava         #+#    #+#             */
/*   Updated: 2024/01/23 13:50:49 by mchenava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#	include <string>
#	include <iostream>

typedef std::string str;

class	Zombie {
	private:
		str name;
	public:
					Zombie();
					Zombie(str name);
					~Zombie();
		void		announce();
		void		setName(str name);
};

void		randomChump(str name);
Zombie*		newZombie(str name);
Zombie* 	zombieHorde(int N, str name );

#endif