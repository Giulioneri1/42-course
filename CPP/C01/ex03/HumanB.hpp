/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:16:32 by gneri             #+#    #+#             */
/*   Updated: 2021/11/11 10:19:23 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanB
{
    private:
        std::string _name;
		Weapon*		_weapon;
    public:
        HumanB(std::string name);
        ~HumanB();
		void	attack();
		void	setWeapon(Weapon& weapon);
        
};


#endif