/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 12:35:28 by gneri             #+#    #+#             */
/*   Updated: 2021/11/17 17:53:56 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_name = name;
	this->Hitpoints = 100;
	this->Energy_points = 50;
	this->Attack_damage = 20;
	std::cout << "ScavTrap " << this->_name << " is spawned" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->_name << " has died" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& obj)
{
	*this = obj;
	std::cout << "A copy of " << this->_name << " has spawned" << std::endl;
}

ScavTrap&	ScavTrap::operator =(const ScavTrap& obj)
{
	this->_name = obj._name;
	this->Hitpoints = obj.Hitpoints;
	this->Energy_points = obj.Energy_points;
	this->Attack_damage = obj.Attack_damage;
	return *this;
}

void	ScavTrap::attack(std::string const & target) const
{
	std::cout << "Scavtrap " << this->_name << " attacks " <<
	target << " causing " << this->Attack_damage << " points of damage" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " has entered in gate keeper mode." << std::endl;
	
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (this->Energy_points - (int)amount < 0)
	{
		std::cout << this->_name << " has only " << this->Energy_points << " available to heal!" <<
		" Cannot heal by " << amount << std::endl;
		return ;
	}
	if (this->Hitpoints < 100 && (this->Hitpoints + amount) <= 100)
	{
		this->Energy_points -= amount;
		this->Hitpoints += amount;
		std::cout << "Scavtrap " << this->_name << " has healed! "
		<< "It now has " << this->Hitpoints << "HP and " << this->Energy_points << "EP remaining" << std::endl;
		return ;
	}
	else
		this->Hitpoints = 100;
	std::cout << this->_name << " is full HP!" << std::endl;
}

void	Scav_VS_Scav(ScavTrap& scavtrap1, ScavTrap& scavtrap2)
{
	scavtrap1.attack(scavtrap2.getName());
	scavtrap2.takeDamage(scavtrap1.getAttackDamage());
}

void	Scav_VS_Clap(ScavTrap& scavtrap, ClapTrap& claptrap)
{
	scavtrap.attack(claptrap.getName());
	claptrap.takeDamage(scavtrap.getAttackDamage());
}

void	Clap_VS_Scav(ClapTrap& claptrap, ScavTrap& scavtrap)
{
	claptrap.attack(scavtrap.getName());
	scavtrap.takeDamage(claptrap.getAttackDamage());
}

