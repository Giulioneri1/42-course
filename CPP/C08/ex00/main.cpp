/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:10:55 by gneri             #+#    #+#             */
/*   Updated: 2022/02/08 10:52:38 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <list>

int main()
{
    try
    {
        int arr[] = {60, 52, 33, 14, 55};

        std::list<int> mylist(arr, arr+5);
    
        std::list<int>::iterator it =  easyfind(mylist, 14);
    
        std::cout << "First occurance at: " << &it << ", value is: " << *it << std::endl;
        
    }
    catch(const char *exp)
    {
        std::cerr << exp << '\n';
    }
}