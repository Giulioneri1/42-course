/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:35:02 by gneri             #+#    #+#             */
/*   Updated: 2021/11/10 13:41:17 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    
    std::string* stringPTR;
    stringPTR = &str;
    
    std::string& stringREF = str;

    std::cout << "Address of str: " << &str << std::endl;
    std::cout << "Address of str through pointer: " << stringPTR << std::endl;
    std::cout << "Address of str through reference: " << &stringREF << std::endl; 
    
    std::cout << "String is: " << *stringPTR << std::endl;
    std::cout << "String is " << stringREF << std::endl;
}