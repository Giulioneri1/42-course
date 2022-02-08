/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:31:46 by gneri             #+#    #+#             */
/*   Updated: 2021/12/20 11:28:35 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	{
    	// const Animal* i = new Cat();
    	// const Animal* j = new Dog();
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
    	// delete j;
    	// delete i;
	}
	
	// { //TEST PERSONALI DEEP COPY
	// 	Dog a;
	// 	Dog b;
	
	// 	b = a;	
	// 	std::cout << "----------------------------------" << std::endl;
	// 	a.getBrain();
	// 	a.printIdeas();
	// 	std::cout << "----------------------------------" << std::endl;
	// 	b.getBrain();
	// 	b.printIdeas();
	// 	std::cout << "----------------------------------" << std::endl;
	// 	b.getBrain()->setIdeas("VINS");
	// 	b.printIdeas();
	// 	std::cout << "----------------------------------" << std::endl;
	// 	a.getBrain();
	// 	a.printIdeas();
	// 	std::cout << "----------------------------------" << std::endl;
	// }

	// {
	// 	Dog *a = new Dog();
	// 	Dog *b = new Dog();

	// 	*b = *a;
	
	// 	std::cout << "----------------------------------" << std::endl;
	// 	a->getBrain();
	// 	a->printIdeas();
	// 	std::cout << "----------------------------------" << std::endl;
	// 	b->getBrain();
	// 	b->printIdeas();
	// 	std::cout << "----------------------------------" << std::endl;
	// 	b->getBrain()->setIdeas("VINS");
	// 	b->printIdeas();
	// 	std::cout << "----------------------------------" << std::endl;
	// 	a->getBrain();
	// 	a->printIdeas();
	// 	std::cout << "----------------------------------" << std::endl;
	// 	delete a;
	// 	delete b;
	// }
	
}