/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:20:14 by gneri             #+#    #+#             */
/*   Updated: 2021/12/20 11:11:21 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

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
};

#endif