/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:08:28 by gneri             #+#    #+#             */
/*   Updated: 2021/11/17 12:32:42 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap claptrap1("Giulio");
	ClapTrap claptrap2("Fulloa");

	claptrap1.setAttackDamage(10);
	attackReal(claptrap1, claptrap2);
	claptrap2.beRepaired(4);
	claptrap2.beRepaired(10);
	claptrap2.beRepaired(6);
	
	claptrap1.attack("fulloa");
	
}