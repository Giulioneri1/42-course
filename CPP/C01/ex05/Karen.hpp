/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:05:04 by gneri             #+#    #+#             */
/*   Updated: 2021/11/11 18:33:57 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
#define KAREN_HPP

#include <iostream>
#include <string>

class Karen
{
	private:
		void	debug()
		{
			std::cout << "I love to get extra bacon " 
			<< "for my 7XL-double-cheese-triple-pickle-special-ketchup burger. " 
			<< "I just love it!" << std::endl;
		}
		void	info();
		void	warning();
		void	error();
	public:
		Karen();
		~Karen();
		void	complain(std::string level);
		
};


#endif