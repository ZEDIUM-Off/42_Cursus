/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchenava <mchenava@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:08:21 by  mchenava         #+#    #+#             */
/*   Updated: 2024/04/09 10:18:15 by mchenava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain* brain;

	public:
		Dog();
		Dog(const Dog& other); // Constructeur de copie
		Dog& operator=(const Dog& other); // Opérateur d'affectation
		virtual ~Dog();

		void makeSound() const;
		const Brain& getBrain() const;
};

#endif
