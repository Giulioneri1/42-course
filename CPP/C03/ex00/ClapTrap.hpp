/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:08:21 by gneri             #+#    #+#             */
/*   Updated: 2021/11/17 15:47:23 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
private:
	std::string _name;
	int			Hitpoints;
	int			Energy_points;
	int			Attack_damage;
public:
	ClapTrap();
	ClapTrap(std::string name);
	~ClapTrap();
	ClapTrap(const ClapTrap& obj);
	ClapTrap&	operator= (const ClapTrap& copy);
	
	void		attack(std::string const & target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	
	void		setAttackDamage(unsigned int amount);
	int			getAttackDamage() const;
	int			getHitpoints() const;
	int			getEnergyPoints() const;
	std::string getName() const;			
};

void	attackReal(ClapTrap& claptrap1, ClapTrap& claptrap2);

#endif