/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:19:17 by gneri             #+#    #+#             */
/*   Updated: 2021/11/12 15:53:51 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		Karen karen;

		karen.complain(argv[1]);
	}
	else
		std::cout << "Wrong number of arguments" << std::endl;	
}