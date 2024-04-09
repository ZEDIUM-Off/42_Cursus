/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchenava <mchenava@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:25:06 by mchenava          #+#    #+#             */
/*   Updated: 2024/04/09 13:20:22 by mchenava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() {
	std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	std::cout << "MateriaSource copy constructor called" << std::endl;
	*this = other;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	std::cout << "MateriaSource assignment operator called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_templates[i])
			delete this->_templates[i];
		if (other._templates[i])
			this->_templates[i] = other._templates[i]->clone();
		else
			this->_templates[i] = NULL;
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		if (this->_templates[i])
			delete this->_templates[i];
}

void	MateriaSource::learnMateria(AMateria* materia) {
	for (int i = 0; i < 4; i++)
		if (!this->_templates[i])
		{
			this->_templates[i] = materia->clone();
			delete materia;
			return;
		}
}

AMateria*	MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++)
		if (this->_templates[i] && this->_templates[i]->getType() == type)
			return this->_templates[i]->clone();
	return 0;
}

