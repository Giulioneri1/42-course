/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:54:18 by gneri             #+#    #+#             */
/*   Updated: 2021/11/26 13:02:47 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
    protected:
        std::string _type;
    public:
        AMateria();
        AMateria(const std::string& type);
        virtual ~AMateria();
        AMateria(const AMateria& amateria);
        
        AMateria& operator=(const AMateria& obj);
        const std::string&  getType() const;
        virtual AMateria*   clone() const = 0;
        virtual void        use(ICharacter& target);
};


#endif