/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:57:35 by gneri             #+#    #+#             */
/*   Updated: 2021/11/17 17:51:39 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(){}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->Hitpoints = 100;
	this->Energy_points = 100;
	this->Attack_damage = 30;
	std::cout << "FragTrap " << this->_name << " is spawned" << std::endl;
}

FragTrap::FragTrap(const FragTrap& obj)
{
	*this = obj;
	std::cout << "A copy of " << this->_name << " has spawned" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_name << " has died" << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& obj)
{
	this->_name = obj._name;
	this->Hitpoints = obj.Hitpoints;
	this->Energy_points = obj.Energy_points;
	this->Attack_damage = obj.Attack_damage;
	return *this;
}

void	FragTrap::beRepaired(unsigned int amount)
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
		std::cout << "Fragtrap " << this->_name << " has healed! "
		<< "It now has " << this->Hitpoints << "HP and " << this->Energy_points << "EP remaining" << std::endl;
		return ;
	}
	else
	{
		if (this->Hitpoints != 100)
			this->Energy_points -= (amount - this->Hitpoints);
		this->Hitpoints = 100;
		std::cout << this->_name << " is full HP!" << std::endl;
	}
}

void		FragTrap::highFivesGuys(void)
{
	std::cout << "High five!" << std::endl;
}

void		FragTrap::attack(std::string const & target) const
{
	std::cout << "Fragtrap " << this->_name << " attacks " <<
	target << " causing " << this->Attack_damage << " points of damage" << std::endl;
}

void	Frag_VS_Frag(FragTrap& fragtrap1, FragTrap& fragtrap2)
{
	fragtrap1.attack(fragtrap2.getName());
	fragtrap2.takeDamage(fragtrap1.getAttackDamage());
}

void	Scav_VS_Frag(ScavTrap& scavtrap, FragTrap& fragtrap)
{
	scavtrap.attack(fragtrap.getName());
	fragtrap.takeDamage(scavtrap.getAttackDamage());
}

void	Frag_VS_Scav(FragTrap& fragtrap, ScavTrap& scavtrap)
{
	fragtrap.attack(scavtrap.getName());
	scavtrap.takeDamage(fragtrap.getAttackDamage());
}

