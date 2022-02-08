/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:22:39 by gneri             #+#    #+#             */
/*   Updated: 2021/12/20 11:27:56 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << this->type << " has been created" << std::endl;
}

Dog::~Dog()
{
	std::cout << this->type << " has died" << std::endl;
	delete this->brain;
}

Dog::Dog(const Dog& dog)
{
	std::cout << "A new dog has been created" << std::endl;
	this->brain = new Brain();
	*this = dog;
}

Dog&	Dog::operator=(const Dog& dog)
{
	this->type = dog.type;
	*(this->brain) = *(dog.brain);
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Bau!" << std::endl;
}

Brain*    Dog::getBrain() const
{
	return this->brain;
}

void	Dog::printIdeas() const
{
	this->brain->printIdeas();
}