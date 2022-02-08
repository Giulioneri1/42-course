/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:54:03 by gneri             #+#    #+#             */
/*   Updated: 2021/11/18 17:38:18 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Wrong Animal")
{
	std::cout << this->type << " has spawned" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << this->type << " has died" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& animal)
{
	*this = animal;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& animal)
{
	this->type = animal.type;
	return *this;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "Wrong animal sound!" << std::endl;
}