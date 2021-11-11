/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:04:58 by gneri             #+#    #+#             */
/*   Updated: 2021/11/11 18:42:24 by gneri            ###   ########.fr       */
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
	void	(Karen::*_debug)() = &Karen::debug;
	if (level == "DEBUG")
	{
		std::cout << _debug << std::endl;
	}
}
