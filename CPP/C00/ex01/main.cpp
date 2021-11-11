/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:48:05 by gneri             #+#    #+#             */
/*   Updated: 2021/11/09 12:48:05 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "phonebook.hpp"

void    choice_message()
{
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "What would you like to do now? " << std::endl;
    std::cout << "- ADD " << std::endl;
    std::cout << "- SEARCH " << std::endl;
    std::cout << "- EXIT " << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
}

void    welcome_message()
{
    std::cout << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "Hello! Welcome to a crappy and old phonebook! " << std::endl;
    std::cout << std::endl << "\t What would you like to do? " << std::endl;
    std::cout << "- ADD " << std::endl;
    std::cout << "- SEARCH " << std::endl;
    std::cout << "- EXIT " << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
}

int main()
{
    phonebook   phonebook;
    std::string  choice;

    welcome_message();
    std::cin >> choice;
    while (1)
    {
        if (choice.compare("ADD") == 0)
            phonebook.add_contact();
        else if (choice.compare("SEARCH") == 0)
            phonebook.print_info();
        else if (choice.compare("EXIT") == 0)
        {
            std::cout << "\t Thanks for using me! See ya." << std::endl;
            return (0);
        }
        choice_message();
        std::cin >> choice;
    }
    return (0);
}