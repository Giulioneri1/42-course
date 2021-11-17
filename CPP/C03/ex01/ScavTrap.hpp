/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 12:35:34 by gneri             #+#    #+#             */
/*   Updated: 2021/11/17 16:24:54 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& obj);
		~ScavTrap();
		void		attack(std::string const & target) const;
		void		beRepaired(unsigned int amount);
		void		guardGate();
		ScavTrap&	operator =(const ScavTrap& obj);
};

void	Scav_VS_Scav(ScavTrap& scavtrap1, ScavTrap& scavtrap2);
void	Scav_VS_Clap(ScavTrap& scavtrap, ClapTrap& claptrap);
void	Clap_VS_Scav(ClapTrap& claptrap, ScavTrap& scavtrap);


#endif