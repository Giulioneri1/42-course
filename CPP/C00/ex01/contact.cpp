/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:48:44 by gneri             #+#    #+#             */
/*   Updated: 2021/11/09 12:48:44 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "contact.hpp"


contact::contact()
{
    fill = false;
}

void    contact::set_first_name(std::string s)
{
    first_name = s;
}

void    contact::set_last_name(std::string s)
{
    last_name = s;
}

void    contact::set_nickname(std::string s)
{
    nickname = s;
}

void    contact::set_phonenumber(std::string s)
{
    phonenumber = s;
}

void    contact::set_darkest_secret(std::string s)
{
    darkest_secret = s;
}

void    contact::set_fill()
{
    fill = true;
}

std::string    contact::get_first_name()
{
    return (first_name);
}
std::string    contact::get_last_name()
{
    return (last_name);
}
std::string    contact::get_nickname()
{
    return  (nickname);
}
std::string    contact::get_phonenumber()
{
    return (phonenumber);
}
std::string    contact::get_darkest_secret()
{
    return (darkest_secret);
}

bool            contact::get_fill()
{
    return (fill);
}


