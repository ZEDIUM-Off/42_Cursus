/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchenava <mchenava@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:43:51 by mchenava          #+#    #+#             */
/*   Updated: 2024/04/09 11:38:43 by mchenava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include "ICharacter.hpp"

class AMateria {
protected:
    std::string _type;

public:
    AMateria(std::string const & type);
    virtual ~AMateria();

    std::string const & getType() const; // Retourne le type de materia
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

#endif
