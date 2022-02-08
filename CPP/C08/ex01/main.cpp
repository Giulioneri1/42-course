/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:37:28 by gneri             #+#    #+#             */
/*   Updated: 2022/02/08 11:02:00 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

int main()
{
    try
    {
        Span sp(10);
    
        srand(time(NULL));
        sp.addNumbers(); //--> add numbers until the capacity
        sp.printVector();
        std::cout << sp.longestSpan() << std::endl;
        std::cout << sp.shortestSpan() << std::endl;
    }
    catch(const char *e)
    {
        std::cout << e << std::endl;
    }

    try
    {
        Span sp(10000);
    
        srand(time(NULL));
        sp.addNumbers();
        sp.addNumber(55); //adding a number after the vector is full
        // sp.printVector();
        std::cout << sp.longestSpan() << std::endl;
        std::cout << sp.shortestSpan() << std::endl;
    }
    catch(const char *e)
    {
        std::cout << e << std::endl;
    }

    {
        Span sp = Span(5);
        sp.addNumber(5);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
}