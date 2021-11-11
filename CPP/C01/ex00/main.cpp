/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:25:55 by gneri             #+#    #+#             */
/*   Updated: 2021/11/09 16:05:35 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"

int main()
{
    Zombie zombie("Vspinell"); //Allocazione in stack dal main. La memoria si libera uno volta finito il main
    zombie.announce();
    
    randomChump("Giulio"); //Allocazione in stack tramite funzione
                            // la memoria si libera automaticamente quando la funzione termina
    
    Zombie* zombie2; //Allocazione in heap dal main
    zombie2 = new Zombie("aviolino");
    zombie2->announce();
    delete zombie2;
    
    Zombie* zombie3;
    zombie3 = newZombie("fulloa"); //Allocazione in heap tramite funzione
    zombie3->announce();
    delete zombie2;
}