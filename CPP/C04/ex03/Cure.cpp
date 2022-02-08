/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:26:52 by gneri             #+#    #+#             */
/*   Updated: 2021/11/26 12:11:08 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    std::cout << this->getType() << " created" << std::endl;
}

Cure::~Cure()
{
    std::cout << this->getType() << " destroyed" << std::endl;
}

Cure::Cure(const Cure& cure)
{
    std::cout << this->getType() << " copy constructor called" << std::endl;
    *this = cure;
}

Cure& Cure::operator=(const Cure& obj)
{
    this->_type = obj._type;
    return *this;
}

AMateria*   Cure::clone() const
{
    return (new Cure(*this));
}

void        Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << " wounds *" << std::endl;
}
