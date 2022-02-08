/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:29:06 by gneri             #+#    #+#             */
/*   Updated: 2021/12/13 12:25:42 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <string>

template<typename T>
void    swap(T &a, T &b)
{
    T c = a;
    a = b;
    b = c;
}

template<typename T>
T   min(T &a, T &b)
{
    return (b <= a ? b : a);
}

template<typename T>
T   max(T &a, T &b)
{
    return (b >= a ? b : a);
}

#endif