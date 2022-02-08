/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:22:54 by gneri             #+#    #+#             */
/*   Updated: 2021/11/18 18:11:31 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	std::cout << this->type << " has been created" << std::endl;
}

Cat::~Cat()
{
	std::cout << this->type << " has died" << std::endl;
}

Cat::Cat(const Cat& Cat)
{
	*this = Cat;	
}

Cat&	Cat::operator=(const Cat& Cat)
{
	this->type = Cat.type;
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Meow.." << std::endl;
}