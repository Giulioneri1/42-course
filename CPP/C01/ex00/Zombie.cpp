/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:02:30 by gneri             #+#    #+#             */
/*   Updated: 2021/11/09 16:48:11 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->_name = name;
    std::cout << "Zombie " << this->_name << " is spawned" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << this->_name << " died" << std::endl;
}

void    Zombie::announce()
{
    std::cout << this->_name << " BraiiiiiiiinnnnzzzZ..." << std::endl;
}
