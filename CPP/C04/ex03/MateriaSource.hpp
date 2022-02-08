/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:55:57 by gneri             #+#    #+#             */
/*   Updated: 2021/11/26 12:28:07 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria *source[4];
    public:
        MateriaSource();
        MateriaSource(const MateriaSource& src);
        ~MateriaSource();

        MateriaSource&  operator=(const MateriaSource& src);
        void learnMateria(AMateria *m);
        AMateria* createMateria(std::string const & type);
};


#endif