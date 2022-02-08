/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:25:10 by gneri             #+#    #+#             */
/*   Updated: 2022/02/08 10:58:15 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span() {}

Span::Span(unsigned int N)
{
    this->capacity = N;
    vec.reserve(N);
}

Span::~Span() {}

void    Span::addNumber(int nbr)
{
    if (vec.size() < vec.capacity())
        vec.push_back(nbr);
    else
        throw ("Container is full, can't add another number");
}

void    Span::addNumbers()
{
    for (unsigned int i = 0; i < capacity; i++)
        addNumber(rand() % MAX_INT);
}

void    Span::printVector()
{
    for (std::vector<int>::iterator it = vec.begin(); it < vec.end(); it++)
        std::cout << *it << std::endl;
    std::cout << "Capacity is: " << vec.capacity() << std::endl;
}

unsigned int Span::shortestSpan()
{
    if (vec.size() < 2)
        throw ("Not enough numbers to calculate the span");
    int span = abs(vec[1] - vec[0]);
    for (std::vector<int>::iterator it = vec.begin(); it < vec.end(); it++)
    {
        for (std::vector<int>::iterator y = it + 1; y < vec.end(); y++)
        {
            int tmp = abs(*y - *it);
            if (tmp < span)
                span = tmp;
        }
    }
    return span;
}

unsigned int Span::longestSpan()
{
    if (vec.size() < 2)
        throw ("Not enough numbers to calculate the span");
    int min = *vec.begin();
    int max = *vec.begin();
    for (std::vector<int>::iterator it = vec.begin(); it < vec.end(); it++)
    {
        if (*it < min)
            min = *it;
        else if (*it > max)
            max = *it;
    }
    std::cout << "Min: " << min << ", Max: " << max << std::endl;
    return (max - min);
}