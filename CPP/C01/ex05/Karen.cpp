/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:04:58 by gneri             #+#    #+#             */
/*   Updated: 2021/11/12 15:18:23 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen(/* args */)
{
}

Karen::~Karen()
{
}

void	Karen::complain(std::string level)
{	
	ptrToFun comment[4];
	std::string Complain[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	comment[0] = &Karen::debug;
	comment[1] = &Karen::info;
	comment[2] = &Karen::warning;
	comment[3] = &Karen::error;
	for (int i = 0; i < 4; i++)
	{
		if (level == Complain[i])
			(this->*comment[i])();
	}
}

void	Karen::debug()
{
	std::cout << "I love to get extra bacon " 
		<< "for my 7XL-double-cheese-triple-pickle-special-ketchup burger. " 
		<< "I just love it!" << std::endl;
}

void	Karen::info()
{
	std::cout << "I cannot believe adding extra bacon cost more money. "
	<< "You don’t put enough! If you did I would not have to ask for it!"
	<< std::endl;
}

void	Karen::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free." << 
	"I’ve been coming here for years and you just started working here last month."
	<< std::endl;
}

void	Karen::error()
{
	std::cout << "This is unacceptable, I want to speak to the manager now."
	<< std::endl;
}
