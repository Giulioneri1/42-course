/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:22:54 by gneri             #+#    #+#             */
/*   Updated: 2021/11/25 14:41:50 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << this->type << " has been created" << std::endl;
}

Cat::~Cat()
{
	std::cout << this->type << " has died" << std::endl;
	delete brain;
}

Cat::Cat(const Cat& Cat)
{
	std::cout << "A new cat has been created" << std::endl;
	this->brain = new Brain();
	*this = Cat;	
}

Cat&	Cat::operator=(const Cat& Cat)
{
	this->type = Cat.type;
	*(this->brain) = *(Cat.brain);
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Meow.." << std::endl;
}

Brain*    Cat::getBrain() const
{
	std::cout << "Indirizzo di brain: " << brain << std::endl;
	return this->brain;
}

void    Cat::printIdeas() const
{
	for (int i = 0; i < 5; i++)
    	std::cout << this->brain->getIdeas()[i] << std::endl;
}
