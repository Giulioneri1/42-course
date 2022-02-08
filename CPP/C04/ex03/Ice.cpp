/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:24:28 by gneri             #+#    #+#             */
/*   Updated: 2021/11/26 12:12:39 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << this->getType() << " created" << std::endl;
}

Ice::~Ice()
{
    std::cout << this->getType() << " destroyed" << std::endl;
}

Ice::Ice(const Ice& ice)
{
    std::cout << this->getType() << " copy constructor called" << std::endl;
    *this = ice;
}

Ice& Ice::operator=(const Ice& obj)
{
    this->_type = obj._type;
    return *this;
}

AMateria*   Ice::clone() const
{
    return (new Ice(*this));
}

void        Ice::use(ICharacter& target)
{
    std::cout <<  "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
