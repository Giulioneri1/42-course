/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:24:45 by gneri             #+#    #+#             */
/*   Updated: 2021/12/13 15:22:12 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template<typename T>
void    print(T &index)
{
    std::cout << index << std::endl;
}

template<typename T>
void    iter(T *addr, int len, void (* func)(T &index))
{
    for (int i = 0; i < len; i++)
        func(addr[i]);
}

#endif