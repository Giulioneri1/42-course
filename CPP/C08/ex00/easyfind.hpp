/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:10:51 by gneri             #+#    #+#             */
/*   Updated: 2022/02/08 10:53:04 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>

template<typename T>
typename T::iterator easyfind(T &cont, int toFind)
{
    for (typename T::iterator it = cont.begin(); it != cont.end(); it++)
    {
        if (*it == toFind)
            return it;
    }
    throw ("Number not found in the container");
}

#endif