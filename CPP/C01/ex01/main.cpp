/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:26:19 by gneri             #+#    #+#             */
/*   Updated: 2021/11/09 17:06:17 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"

int main()
{
    Zombie *horde;
    int    amount;

    amount = 20;
    horde = zombieHorde(amount, "Giulio");
    for (int i = 0; i < amount; i++)
        horde[i].announce();
    delete [] horde;
}
