/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 12:45:10 by gneri             #+#    #+#             */
/*   Updated: 2021/11/15 14:40:34 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->fp_value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
	// *this = copy;
	this->fp_value = copy.fp_value;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed&  copy)
{
	this->fp_value = copy.fp_value;
	
	std::cout << "Assignation operator called" << std::endl;
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
