/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:04:51 by gneri             #+#    #+#             */
/*   Updated: 2021/11/12 15:17:31 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int main()
{
	Karen karen;
	std::string Complain[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	srand(time(NULL));
	int i = rand() % 4;
	karen.complain(Complain[i]);
}