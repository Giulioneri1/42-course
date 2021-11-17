/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:58:26 by gneri             #+#    #+#             */
/*   Updated: 2021/11/17 17:52:25 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap	claptrap("Fulloa");
	ScavTrap	scavtrap("Giulio");
	FragTrap	fragtrap("Vegeta");
	FragTrap	fragtrap2("Goku");
	
	{
		std::cout << "//------------------------------------------------------//" << std::endl;
		Frag_VS_Scav(fragtrap, scavtrap);
		// std::cout << scavtrap.getHitpoints() << std::endl;
		scavtrap.beRepaired(100);
		scavtrap.beRepaired(10);
		std::cout << "//------------------------------------------------------//" << std::endl;
	}
	
	{
		Frag_VS_Frag(fragtrap, fragtrap2);
		fragtrap2.beRepaired(100);
		std::cout << "Energy points: " << fragtrap2.getEnergyPoints() << std::endl;
		std::cout << "//------------------------------------------------------//" << std::endl;
	}
	
	{
		Scav_VS_Frag(scavtrap, fragtrap);
		fragtrap.beRepaired(5);
		fragtrap.beRepaired(15);
		std::cout << "//------------------------------------------------------//" << std::endl;
	}
	
	{
		fragtrap.attack("Fulloa");
		fragtrap.highFivesGuys();	
		std::cout << "//------------------------------------------------------//" << std::endl;
	}
}