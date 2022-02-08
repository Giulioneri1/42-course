/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:22:45 by gneri             #+#    #+#             */
/*   Updated: 2021/12/20 11:42:09 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *brain;
	public:
		Cat();
		Cat(const Cat& cat);
		virtual ~Cat();
		
		Cat&		operator=(const Cat& cat);
		void		makeSound() const;
		Brain*		getBrain() const;
		void   		printIdeas() const;
};

#endif