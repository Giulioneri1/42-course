/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:32:55 by gneri             #+#    #+#             */
/*   Updated: 2021/12/20 11:37:34 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

class Animal
{
	protected:
		std::string	type;
	public:
		Animal();
		Animal(const Animal& animal);
		virtual ~Animal();
		
		Animal&			operator= (const Animal& animal);
		virtual void	makeSound() const; // virtual --> method can be override by child class
		std::string		getType() const;
		virtual Brain*	getBrain() const = 0;
		virtual void	printIdeas() const = 0;
};

#endif