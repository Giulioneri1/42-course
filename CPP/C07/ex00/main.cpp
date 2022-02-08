/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:29:11 by gneri             #+#    #+#             */
/*   Updated: 2021/12/13 12:05:39 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main( void )
{
    float a = 2.34f;
    float b = 2.32f;
    
    std::cout << "a = " << a << ", b = " << b << std::endl;
    swap( a, b );
    std::cout << "AFTER SWAP-> " << " a = " << a << ", b = " << b << std::endl;
    
    std::cout << "min( a, b ) = " << min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << max( a, b ) << std::endl;
    
    std::string c = "chaine1";
    std::string d = "chaine2";
    std::cout << "c = " << c << ", d = " << d << std::endl;
    swap(c, d);
    std::cout << "AFTER SWAP-> " << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << max( c, d ) << std::endl;
    return 0;
}