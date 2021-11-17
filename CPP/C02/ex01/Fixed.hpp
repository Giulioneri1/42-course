/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 11:36:28 by gneri             #+#    #+#             */
/*   Updated: 2021/11/15 17:31:51 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

#define MIN_INT	-8388608
#define MAX_INT 8388607

class Fixed
{
private:
	int fp_value;
	static const int bits = 8; //grandezza parte decimale
public:
	Fixed();
	Fixed(const int n);
	Fixed(const float f);
	Fixed(const Fixed& copy);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
	Fixed& operator = (const Fixed& copy);		
};

std::ostream& operator << (std::ostream& stream, const Fixed& copy);

#endif
