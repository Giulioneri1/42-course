/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:09:17 by gneri             #+#    #+#             */
/*   Updated: 2021/11/10 16:21:28 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>


class HumanA
{
    private:
        std::string _name;
		Weapon&      _weapon;
    public:
        HumanA(std::string name, Weapon& weapon);
        ~HumanA();
		void	attack();
        
};


#endif