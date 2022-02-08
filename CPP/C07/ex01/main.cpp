/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:26:01 by gneri             #+#    #+#             */
/*   Updated: 2021/12/13 15:22:19 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
    std::string example[3] = {"Ciao", "come", "stai"};
    
    iter(example, 3, print);
    
    int     example2[3] = {1, 2, 3};

    iter(example2, 3, print);

    char    example3[6] = {'a', 'd', 'd', 'i', 'o', 's'};

    iter(example3, 6, print);
    
}