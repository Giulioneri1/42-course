/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:57:35 by gneri             #+#    #+#             */
/*   Updated: 2021/11/09 16:48:19 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
    private:
        std::string  _name;
    public:
        Zombie(std::string name);
        ~Zombie();
        void    announce(void);
};

void    randomChump(std::string name);
Zombie  *newZombie(std::string  name);

#endif