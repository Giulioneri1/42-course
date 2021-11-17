/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:57:42 by gneri             #+#    #+#             */
/*   Updated: 2021/11/17 17:31:07 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

class FragTrap : public ClapTrap
{
	private:
		
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap& obj);
		~FragTrap();
		
		void		highFivesGuys(void);
		void		attack(std::string const & target) const;
		void		beRepaired(unsigned int amount);
		FragTrap&	operator =(const FragTrap& obj);
};

void	Frag_VS_Frag(FragTrap& fragtrap1, FragTrap& fragtrap2);
void	Scav_VS_Frag(ScavTrap& scavtrap, FragTrap& fragtrap);
void	Frag_VS_Scav(FragTrap& fragtrap, ScavTrap& scavtrap);

#endif