/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:24:10 by gneri             #+#    #+#             */
/*   Updated: 2022/02/08 10:56:31 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#define MAX_INT 2147483647

class Span
{
    private:
        unsigned int capacity;
        std::vector<int> vec;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span& src);
        ~Span();

        Span& operator=(const Span& src);
        
        void            addNumber(int nbr);
        void            addNumbers();
        unsigned int    shortestSpan();
        unsigned int    longestSpan();
        void            printVector();
};


#endif