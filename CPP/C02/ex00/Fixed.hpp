/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 12:45:18 by gneri             #+#    #+#             */
/*   Updated: 2021/11/15 14:32:09 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
	private:
		int fp_value;
		static const int bits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed& copy);
		int getRawBits(void) const; //return the raw value of fixed point value
		void setRawBits(int const raw); //set the raw value of the fixed point value;
		Fixed& operator = (const Fixed& copy);
};


#endif