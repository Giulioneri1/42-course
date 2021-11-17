/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:35:12 by gneri             #+#    #+#             */
/*   Updated: 2021/11/16 17:01:15 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->fp_value = 0;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	if (n > MIN_INT && n < MAX_INT)
		this->fp_value = n * 256; // n << this->bits; sposta il numero di 8 bit a sinistra per lasciare la parte frazionale
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	this->fp_value = roundf(f * 256); // 256 = 1 << this->bits (ovvero 8bit)
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
	// this->fp_value = copy.fp_value;
}

Fixed& Fixed::operator=(const Fixed&  copy)
{
	std::cout << "Assignation operator called" << std::endl;
	
	this->fp_value = copy.fp_value;
	return *this; //this = puntatore a questo oggetto. Ritorno dereferenziato per avere l'oggetto stesso.
}

void	Fixed::setRawBits(int const raw)
{
	this->fp_value = raw;
}

int		Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->fp_value;
}

int		Fixed::toInt() const
{
	return (this->fp_value / 256);
}

float	Fixed::toFloat() const
{
	return ((float)this->fp_value / 256);
}

std::ostream& operator << (std::ostream& stream, const Fixed& copy)
{
	stream << copy.toFloat();
	return stream;
}

bool	Fixed::operator > (const Fixed& obj) const
{
	return (this->fp_value > obj.fp_value);
}

bool	Fixed::operator < (const Fixed& obj) const
{
	return (this->fp_value < obj.fp_value);
}

bool	Fixed::operator >=(const Fixed& obj) const
{
	return (this->fp_value >= obj.fp_value);
}

bool	Fixed::operator <=(const Fixed& obj) const
{
	return (this->fp_value <= obj.fp_value);
}

bool	Fixed::operator ==(const Fixed& obj) const
{
	return (this->fp_value == obj.fp_value);
}

bool	Fixed::operator !=(const Fixed& obj) const
{
	return (this->fp_value != obj.fp_value);
}

Fixed	Fixed::operator +(const Fixed& obj) const
{
	return Fixed(this->toFloat() + obj.toFloat());
}

Fixed	Fixed::operator -(const Fixed& obj) const
{
	return Fixed(this->toFloat() - obj.toFloat());
}

Fixed	Fixed::operator *(const Fixed& obj) const
{
	return Fixed(this->toFloat() * obj.toFloat());
}

Fixed	Fixed::operator /(const Fixed& obj) const
{
	return Fixed(this->toFloat() / obj.toFloat());
}

Fixed&	Fixed::operator ++()
{
	this->fp_value++;
	return *this;
}

Fixed& Fixed::operator --()
{
	this->fp_value--;
	return *this;
}

Fixed	Fixed::operator ++(int)
{
	/*Fixed tmp; --> tramite costruttore default;
	tmp.fp_value = this->fp_value;
	this->fp_value++; */

	Fixed tmp = *this; // == tmp.fp_value = this->fp_value tramite overload op. assgn
	++(*this); // chiama il preincremento su this->fp_value
	return tmp;
}

Fixed	Fixed::operator --(int)
{
	Fixed tmp = *this; 
	--(*this);
	return tmp;
}

Fixed& Fixed::min(Fixed& obj1, Fixed& obj2)
{
	return (obj1 < obj2 ? obj1 : obj2);
}

const Fixed& Fixed::min(const Fixed& obj1, const Fixed& obj2)
{
	return (obj1 < obj2 ? obj1 : obj2);
}

Fixed& Fixed::max(Fixed& obj1, Fixed& obj2)
{
	return (obj1 > obj2 ? obj1 : obj2);
}

const Fixed& Fixed::max(const Fixed& obj1, const Fixed& obj2)
{
	return (obj1 > obj2 ? obj1 : obj2);
}




