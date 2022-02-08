/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:08:48 by gneri             #+#    #+#             */
/*   Updated: 2022/02/08 11:07:44 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template<typename T>
class Mutantstack : public std::stack<T>
{
    public:
        Mutantstack(){}
        Mutantstack(const Mutantstack<T>& src)
        {
            *this = src;
        }
        
	    Mutantstack<T>& operator=(const Mutantstack<T>& src) 
	    {
		    this->c = src.c;
		    return *this;
	    }
        
        ~Mutantstack(){}
    
        typedef typename std::stack<T>::container_type::iterator iterator;
    
        iterator begin()
        {
            return this->c.begin();
        }
    
        iterator   end()
        {
            return this->c.end();
        }
};

#endif