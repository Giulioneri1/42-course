/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:22:39 by gneri             #+#    #+#             */
/*   Updated: 2021/11/18 18:11:53 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	std::cout << this->type << " has been created" << std::endl;
}

Dog::~Dog()
{
	std::cout << this->type << " has died" << std::endl;
}

Dog::Dog(const Dog& dog)
{
	*this = dog;	
}

Dog&	Dog::operator=(const Dog& dog)
{
	this->type = dog.type;
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Bau!" << std::endl;
}