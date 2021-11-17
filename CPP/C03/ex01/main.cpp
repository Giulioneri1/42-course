/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 12:35:04 by gneri             #+#    #+#             */
/*   Updated: 2021/11/17 16:30:13 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap	claptrap("Fulloa");
	ClapTrap	claptrap2("Mario");
	ScavTrap	scavtrap("Giulio");
	ScavTrap	scavtrap2("Vegeta");
	
	{
		std::cout << "//------------------------------------------------------//" << std::endl;
		Scav_VS_Clap(scavtrap2, claptrap);
		// std::cout << claptrap.getHitpoints() << std::endl;
		claptrap.beRepaired(15);
		claptrap.beRepaired(10);
		std::cout << "//------------------------------------------------------//" << std::endl;
	}
	
	{
		Scav_VS_Scav(scavtrap, scavtrap2);
		// std::cout << scavtrap2.getHitpoints() << std::endl;
		scavtrap2.beRepaired(100);
		scavtrap2.beRepaired(15);
		std::cout << "//------------------------------------------------------//" << std::endl;
	}
	
	{
		Clap_VS_Scav(claptrap, scavtrap);
		// std::cout << scavtrap.getHitpoints() << std::endl;
		scavtrap.beRepaired(100);
		scavtrap.beRepaired(15);
		std::cout << "//------------------------------------------------------//" << std::endl;
	}
	
	{
		scavtrap.attack("Fulloa");
		scavtrap.guardGate();	
		std::cout << "//------------------------------------------------------//" << std::endl;
	}
}