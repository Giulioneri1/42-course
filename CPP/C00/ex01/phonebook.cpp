/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:48:24 by gneri             #+#    #+#             */
/*   Updated: 2021/11/09 12:48:26 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "phonebook.hpp"

phonebook::phonebook()
{
    index = 0;
}

void    phonebook::add_contact()
{
    std::string input;

    std::cout << "\t OK! Let's add you to the contact list!" << std::endl << std::endl;
    std::cout << "Insert your first name: ";
    std::getline(std::cin, input);
    std::getline(std::cin, input);
    contact[index].set_first_name(input);
    std::cout << "Insert your last name: ";
    std::getline(std::cin, input);
    contact[index].set_last_name(input);
    std::cout << "Insert your nickname: ";
    std::getline(std::cin, input);
    contact[index].set_nickname(input);
    std::cout << "Insert your phone number: ";
    std::getline(std::cin, input);
    contact[index].set_phonenumber(input);
    std::cout << "Insert your darkest secret: ";
    std::getline(std::cin, input);
    contact[index].set_darkest_secret(input);
    contact[index].set_fill();
    if (index < 7)
        index++;
    else
        index = 0;
    std::cout << std::endl << "\t Contact added succesfully!" << std::endl;
}

std::string set_string(std::string input)
{
    int count;
    int len = input.length();
    if (len > 10)
    {
        input[9] = '.';
        count = 10;
        while (count < len)
            input[count++] = 0;
    }
    return (input);
}

void        phonebook::print_info()
{
    int index = 0;
    if (!contact[index].get_fill())
    {
        std::cout << "\t No contact has been added. Try adding one first." << std::endl;
        return ;
    }
    std::cout << "     Index|First Name| Last Name|  Nickname|" << std::endl;
    while (contact[index].get_fill() == true)
    {
        std::cout.width(10);
        std::cout << index << "|";
        std::cout.width(10);
        std::cout << set_string(contact[index].get_first_name()) << "|";
        std::cout.width(10);
        std::cout << set_string(contact[index].get_last_name()) << "|";
        std::cout.width(10);
        std::cout << set_string(contact[index].get_nickname()) << "|" << std::endl;
        index++;
    }
    std::cout << "Which contact do you want to have info about? Insert index:" << std::endl;
    std::cin >> index;
    if (index >= 0 && index < 8 && contact[index].get_fill() == true)
    {
        std::cout << std::endl << "First Name: " << contact[index].get_first_name() << std::endl;
		std::cout << "Last Name: " << contact[index].get_last_name() << std::endl;
		std::cout << "Nickname: " << contact[index].get_nickname() << std::endl;
		std::cout << "Phone Number: " << contact[index].get_phonenumber() << std::endl;
		std::cout << "Darkest Secret: " << contact[index].get_darkest_secret() << std::endl;
        std::cout << std::endl << "\t Now you know something more about " << contact[index].get_first_name() << std::endl;
    }
    else
    {
        std::cin.clear();
        std::cin.ignore(9999, '\n');
        std::cout << std::endl << "\t Wrong index! Try again." << std::endl;
    }
}
