/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:33:02 by gneri             #+#    #+#             */
/*   Updated: 2021/12/20 11:38:32 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << type << " has been created" << std::endl;
}

Animal::~Animal()
{
	std::cout << type << " has died" << std::endl;
}

Animal::Animal(const Animal& animal)
{
	*this = animal;
}

Animal&		Animal::operator= (const Animal& animal)
{
	this->type = animal.type;
	return *this;
}

void	Animal::makeSound() const
{
	std::cout << "No specific animal no specific sound!" << std::endl;
}

std::string Animal::getType() const
{
	return this->type;
}
