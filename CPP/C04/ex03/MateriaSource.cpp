/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:56:40 by gneri             #+#    #+#             */
/*   Updated: 2021/11/26 12:40:25 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        this->source[i] = NULL;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        delete this->source[i];
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
    *this = src;
}

MateriaSource&  MateriaSource::operator=(const MateriaSource& src)
{
    int i = 0;
    while (this->source[i] != NULL)
    {
        delete this->source[i];
        i++;
    }
    for (int i = 0; i < 4; i++)
        if (src.source[i] != NULL)
            this->source[i] = src.source[i]->clone();
    return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
    for (int i = 0; i < 4; i++)
        if (this->source[i] == NULL)
        {
            this->source[i] = m;
            break ;
        }   
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->source[i] != NULL && this->source[i]->getType() == type)
            return (this->source[i]->clone());
    }
    return 0;
}