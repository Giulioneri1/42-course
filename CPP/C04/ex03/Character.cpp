/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:09:52 by gneri             #+#    #+#             */
/*   Updated: 2021/11/26 12:58:29 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
    std::cout << "Default character constructor called" << std::endl;
}

Character::Character(const std::string& name) : _name(name)
{
    std::cout << this->_name << " constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
}

Character::~Character()
{
    std::cout << this->_name << " destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        delete this->inventory[i];
}

Character::Character(const Character& chr)
{
    std::cout << this->_name << " copy constructor called" << std::endl;
    *this = chr;
}

Character&  Character::operator=(const Character& obj)
{
    this->_name = obj._name;
    int i = 0;
    while (this->inventory[i] != NULL)
    {
        delete this->inventory[i];
        i++;
    }
    for (int i = 0; i < 4; i++)
        if (obj.inventory[i] != NULL)
            this->inventory[i] = obj.inventory[i]->clone();
    return *this;
}

void    Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i] == NULL)
        {
            this->inventory[i] = m;
            break ;
        }
    }
}

void    Character::unequip(int idx)
{
    if (idx >= 0 && idx <= 4)
        this->inventory[idx] = NULL;
}

void    Character::use(int idx, ICharacter& target)
{
    if ((idx >= 0 && idx <= 4) && this->inventory[idx] != NULL)
        this->inventory[idx]->use(target);
}

const std::string&  Character::getName() const
{
    return this->_name;
}