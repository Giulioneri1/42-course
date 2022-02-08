/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:54:25 by gneri             #+#    #+#             */
/*   Updated: 2021/11/26 12:09:15 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
    std::cout << "Default constructor called" << std::endl;
}

AMateria::AMateria(const std::string& type) : _type(type)
{
    std::cout << "Constructor called" << std::endl;
}

AMateria::~AMateria()
{
    std::cout << "Destructor called" << std::endl;
}

AMateria::AMateria(const AMateria& amateria)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = amateria;
}

AMateria& AMateria::operator=(const AMateria& obj)
{
    this->_type = obj._type;
    return *this;
}

const std::string&  AMateria::getType() const
{
    return this->_type;
}

void    AMateria::use(ICharacter& target)
{
    std::cout << "Abstract materia does not have a specific job to do against " << target.getName() << std::endl;
}
