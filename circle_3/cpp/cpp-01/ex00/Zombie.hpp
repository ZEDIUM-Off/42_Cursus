/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:05:09 by  mchenava         #+#    #+#             */
/*   Updated: 2023/12/01 15:27:50 by  mchenava        ###   ########.fr       */
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
};

void		randomChump(str name);
Zombie*	newZombie(str name);

#endif