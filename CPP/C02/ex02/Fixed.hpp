/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:35:07 by gneri             #+#    #+#             */
/*   Updated: 2021/11/16 17:01:01 by gneri            ###   ########.fr       */
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
	bool	operator > (const Fixed& obj) const;
	bool	operator < (const Fixed& obj) const;
	bool	operator >= (const Fixed& obj) const;
	bool	operator <= (const Fixed& obj) const;
	bool	operator == (const Fixed& obj) const;
	bool	operator != (const Fixed& obj) const;
	Fixed	operator +(const Fixed& obj) const;
	Fixed	operator -(const Fixed& obj) const;
	Fixed	operator *(const Fixed& obj) const;
	Fixed	operator /(const Fixed& obj) const;
	Fixed&	operator ++();
	Fixed&	operator --();
	Fixed	operator ++(int);
	Fixed	operator --(int);
	static Fixed& min(Fixed& obj1, Fixed& obj2);
	static const Fixed& min(const Fixed& obj1, const Fixed& obj2);
	static Fixed& max(Fixed& obj1, Fixed& obj2);
	static const Fixed& max(const Fixed& obj1, const Fixed& obj2);
};

std::ostream& operator << (std::ostream& stream, const Fixed& copy);

#endif