/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:00:43 by gneri             #+#    #+#             */
/*   Updated: 2021/12/20 11:14:51 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	j->makeSound();
	i->makeSound(); 
	meta->makeSound();
	
	delete meta;
	delete j;
	delete i;
	
	std::cout << "----------------------------------" << std::endl;
	const WrongAnimal* vins = new WrongCat();
	const WrongCat *vins2 = new WrongCat();
	vins->makeSound();
	vins2->makeSound();
	delete vins;
	delete vins2;
}
