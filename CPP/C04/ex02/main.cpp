/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:31:46 by gneri             #+#    #+#             */
/*   Updated: 2021/12/20 11:41:41 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	{
    	const Animal* i = new Cat();
    	const Animal* j = new Dog();
    	const Animal* arr[10];
	
    	for (int i = 0; i < 10; i++)
    	{
			if (i % 2 == 0)
				arr[i] = new Cat();
			else
				arr[i]= new Dog();
    	    arr[i]->makeSound();
			std::cout << i << std::endl;
    	}
		
		arr[0]->getBrain();
		arr[0]->printIdeas();
		std::cout << "----------------------------------" << std::endl;
		arr[0]->getBrain()->setIdeas("VINS");
		arr[0]->printIdeas();
		std::cout << "----------------------------------" << std::endl;
		arr[1]->getBrain();
		arr[1]->printIdeas();
		std::cout << "----------------------------------" << std::endl;

		for (int i = 0; i < 10; i++)
		{
			delete arr[i];
		}
    	delete j;
    	delete i;
	}
	
	// {
	// 	Animal fake;
	// 	std::cout << fake.makeSound() << std::endl;
	// }
}