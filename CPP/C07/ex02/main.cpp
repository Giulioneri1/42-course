/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:23:32 by gneri             #+#    #+#             */
/*   Updated: 2022/01/14 12:10:43 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
    {
        Array<int> array(5);
    
        std::cout << "Size of array: " << array.size() << std::endl;
        for (int i = 0; i < 5; i++)
            std::cout << array[i] << std::endl;
        array[0] = 42;
        array[1] = 10;
        array[2] = 100;
        std::cout << std::endl;
        for (int i = 0; i < 5; i++)
            std::cout << array[i] << std::endl;
    }
    {
        Array<std::string> array(3);
        
        std::cout << "Size of array: " << array.size() << std::endl;

        for (int i = 0; i < 3; i++)
            std::cout << array[i] << std::endl;
        for (int i = 0; i < 3; i++)
        {
            array[i] = "I'm Full now!";
            std::cout << array[i] << std::endl;
        }
    }
    {
        Array<char> array(3);
        
        std::cout << "Size of array: " << array.size() << std::endl;

        for (int i = 0; i < 3; i++)
            std::cout << array[i] << std::endl;
          for (int i = 0; i < 3; i++)
        {
            array[i] = 'P';
            std::cout << array[i] << std::endl;
        }
    }
}