/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:53:39 by gneri             #+#    #+#             */
/*   Updated: 2021/11/18 17:37:58 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "Fake cat has spawned" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "Wrong cat is dead" << std::endl;
}

WrongCat::WrongCat(const WrongCat& cat)
{
	*this = cat;	
}

WrongCat&	WrongCat::operator=(const WrongCat& cat)
{
	this->type = cat.type;
	return *this;
}

void	WrongCat::makeSound() const
{
	std::cout << "Fake meow!!!" << std::endl;
}