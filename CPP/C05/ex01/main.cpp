/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:50:58 by gneri             #+#    #+#             */
/*   Updated: 2021/11/30 13:03:43 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    std::cout << "-----------------------------------------" << std::endl; 
    try //CASE SIGNED OK
    {
        Bureaucrat burocrat("Vins", 130);
        std::cout << burocrat << std::endl;
        Form       modulo("Modulo adesione 5778", 135, 140);
        std::cout << modulo << std::endl;
        modulo.beSigned(burocrat);
        std::cout << modulo << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "-----------------------------------------" << std::endl; 
    try //CASE FAIL TO SIGN
    {
        
        Bureaucrat burocrat("Fulloa", 130);
        std::cout << burocrat << std::endl;
        Form       modulo("Modulo adesione 5778", 100, 140);
        std::cout << modulo << std::endl;
        burocrat.signForm(modulo);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "-----------------------------------------" << std::endl;
   try //CASE ALREADY SIGNED
    {
        Bureaucrat burocrat("Aviolino", 130);
        std::cout << burocrat << std::endl;
        Form       modulo("Modulo adesione 5778", 130, 140);
        std::cout << modulo << std::endl;
        modulo.beSigned(burocrat);
        std::cout << modulo << std::endl;
        burocrat.signForm(modulo);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}