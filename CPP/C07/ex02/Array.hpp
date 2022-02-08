/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:23:30 by gneri             #+#    #+#             */
/*   Updated: 2022/01/14 12:03:21 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <exception>

template<typename T>
class Array
{
    private:
        T *element;
        unsigned int _size;
    public:
        Array()
        {
            this->_size = 0;
            element = new T[0];
        }
        Array(unsigned int n)
        {
            this->_size = n;
			element = new T[n];
			for (unsigned int i = 0; i < n; i++)
				element[i] = T();
        }
        
        Array(const Array& arr)
        {
            *this = arr;
        }

        ~Array()
        {
            delete []element;
        }
        
        Array& operator=(const Array& arr)
        {
            if (this->element)
                delete []element;
            this->_size = arr._size;
            this->element = new T[arr._size];
            for (int i = 0; i < _size; i++)
                this->element[i] = arr.element[i];
            return *this;
        }

        T& operator[](unsigned int index)
        {
			if (index >= this->_size)
				throw std::out_of_range("Index out of range");
			return this->element[index];
        }
        
        int size() const
        {
            return (this->_size);
        }
};


#endif