/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:46:29 by gneri             #+#    #+#             */
/*   Updated: 2021/11/29 17:42:09 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try //CASE TOO HIGH
    {
        Bureaucrat example1("Vins", -50);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try //CASE TOO HIGH
    {
        Bureaucrat example2("Vins", 0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try //CASE TOO LOW
    {
        Bureaucrat example3("Vins", 151);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try //CORRECT CASE
    {
        Bureaucrat example("Fulloa", 10);
        std::cout << example << std::endl;
        example.incrGrade();
        std::cout << example << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

      try //CORRECT CASE
    {
        Bureaucrat example("Fulloa", 150);
        std::cout << example << std::endl;
        example.incrGrade();
        std::cout << example << std::endl;

        Bureaucrat example2("Vins", 1);
        std::cout << example2 << std::endl;
        example2.decrGrade();
        std::cout << example2 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    } 
}