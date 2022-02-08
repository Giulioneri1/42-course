/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:22:33 by gneri             #+#    #+#             */
/*   Updated: 2021/12/20 11:29:37 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *brain;
	public:
		Dog();
		Dog(const Dog& dog);
		virtual ~Dog();

		Dog&		operator=(const Dog& dog);
		void		makeSound() const;
		Brain*		getBrain() const;
		void   		printIdeas() const;
		
};

#endif