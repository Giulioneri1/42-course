/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:08:14 by gneri             #+#    #+#             */
/*   Updated: 2021/11/17 12:31:53 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : Hitpoints(10), Energy_points(10), Attack_damage(0)
{
	this->_name = name;
	std::cout << "Claptrap " << this->_name << " has spawned" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Claptrap " << this->_name << " has died" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj)
{
	*this = obj;
	std::cout << "A copy of " << this->_name << "has been created" << std::endl;	
}

void	ClapTrap::attack(std::string const & target)
{
	std::cout << "ClapTrap " << this->_name << " attacks " <<
	target << " causing " << this->Attack_damage << " points of damage" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->Hitpoints > (int)amount)
		this->Hitpoints -= amount;
	else
		this->Hitpoints = 0;
	std::cout << this->_name << " has taken " << amount << " points of damage!"
	<< " It has now " << this->Hitpoints << " hitpoints" << std::endl;

}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->Energy_points - (int)amount < 0)
	{
		std::cout << this->_name << " has only " << this->Energy_points << " available to heal!" <<
		" Cannot heal by " << amount << std::endl;
		return ;
	}
	if (this->Hitpoints < 10 && (this->Hitpoints + amount) <= 10)
	{
		this->Energy_points -= amount;
		this->Hitpoints += amount;
		std::cout << "Claptrap " << this->_name << " has healed! "
		<< "It now has " << this->Hitpoints << " hitpoints" << " and " << this->Energy_points << " energy points remaining" << std::endl;
		return ;
	}
	else
		this->Hitpoints = 10;
	std::cout << this->_name << " is already full HP!" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& obj)
{
	this->_name = obj._name;
	this->Hitpoints = obj.Hitpoints;
	this->Energy_points = obj.Energy_points;
	this->Attack_damage = obj.Attack_damage;
	return *this;
}

void	ClapTrap::setAttackDamage(unsigned int amount)
{
	if (amount > 0)
		this->Attack_damage = amount;
}

int	ClapTrap::getAttackDamage() const
{
	return this->Attack_damage;
}

std::string		ClapTrap::getName() const
{
	return this->_name;	
}

int		ClapTrap::getHitpoints() const
{
	return this->Hitpoints;
}

int		ClapTrap::getEnergyPoints() const
{
	return this->Energy_points;
}

void	attackReal(ClapTrap& claptrap1, ClapTrap& claptrap2)
{
	claptrap1.attack(claptrap2.getName());
	std::cout << claptrap2.getHitpoints() << std::endl;
	claptrap2.takeDamage(claptrap1.getAttackDamage());
}
