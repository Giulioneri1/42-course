/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:50:58 by gneri             #+#    #+#             */
/*   Updated: 2021/12/01 09:49:29 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::cout << "------------------//SHRUBBERY FORM SIGNED AND EXECUTED//-----------------------" << std::endl;
    try 
    {
        std::cout << std::endl;
        Bureaucrat burocrat("Vins", 130);
        std::cout << burocrat << std::endl;
        AForm *modulo = new ShrubberyCreationForm("Roma");
        std::cout << *modulo << std::endl;
        burocrat.signForm(*modulo);
        std::cout << *modulo << std::endl;
        burocrat.executeForm(*modulo);
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "--------------------//SHRUBBERY FORM SIGNED BUT NOT EXECUTED//---------------------" << std::endl;
    try 
    {
        std::cout << std::endl;
        Bureaucrat burocrat("Fulloa", 145);
        std::cout << burocrat << std::endl;
        ShrubberyCreationForm       modulo("Roma");
        std::cout << modulo << std::endl;
        burocrat.signForm(modulo);
        std::cout << modulo << std::endl;
        burocrat.executeForm(modulo);
        std::cout << std::endl;
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "-------------------//SHRUBBERY FORM NOT SIGNED//---------------------" << std::endl;
    try 
    {
        std::cout << std::endl;
        Bureaucrat burocrat("Mbus", 149);
        std::cout << burocrat << std::endl;
        ShrubberyCreationForm       modulo("Roma");
        std::cout << modulo << std::endl;
        modulo.beSigned(burocrat);
        std::cout << modulo << std::endl;
        modulo.execute(burocrat);
        std::cout << std::endl;
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "-------------------//ROBOTOMY FORM SIGNED AND EXECUTED//----------------------" << std::endl;
    try 
    {
        std::cout << std::endl;
        Bureaucrat burocrat("Aviolini", 45);
        std::cout << burocrat << std::endl;
        AForm *modulo = new RobotomyRequestForm(burocrat.getName());
        std::cout << *modulo << std::endl;
        burocrat.signForm(*modulo);
        std::cout << *modulo << std::endl;
        burocrat.executeForm(*modulo);
        std::cout << std::endl;
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "-----------------//ROBOTOMY FORM SIGNED NOT EXECUTED//------------------------" << std::endl;
    try 
    {
        std::cout << std::endl;
        Bureaucrat burocrat("Fgradia", 72);
        std::cout << burocrat << std::endl;
        RobotomyRequestForm       modulo(burocrat.getName());
        std::cout << modulo << std::endl;
        modulo.beSigned(burocrat);
        std::cout << modulo << std::endl;
        modulo.execute(burocrat);
        std::cout << std::endl;
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "------------------//ROBOTOMY NOT SIGNED//-----------------------" << std::endl;
    try 
    {
        std::cout << std::endl;
        Bureaucrat burocrat("Gneri", 73);
        std::cout << burocrat << std::endl;
        RobotomyRequestForm       modulo(burocrat.getName());
        std::cout << modulo << std::endl;
        modulo.beSigned(burocrat);
        std::cout << modulo << std::endl;
        modulo.execute(burocrat);
        std::cout << std::endl;
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "--------------------//PRESIDENTIAL FORM SIGNED AND EXECUTED//---------------------" << std::endl;
    try 
    {
        std::cout << std::endl;
        Bureaucrat burocrat("Berlusconi", 2);
        std::cout << burocrat << std::endl;
        AForm *modulo = new PresidentialPardonForm("Berlusconi");
        std::cout << *modulo << std::endl;
        modulo->beSigned(burocrat);
        std::cout << *modulo << std::endl;
        modulo->execute(burocrat);
        std::cout << std::endl;
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "-------------------//PRESIDENTIAL FORM SIGNED NOT EXECUTED//----------------------" << std::endl;
    try 
    {
        std::cout << std::endl;
        Bureaucrat burocrat("Putin", 25);
        std::cout << burocrat << std::endl;
        PresidentialPardonForm       modulo(burocrat.getName());
        std::cout << modulo << std::endl;
        modulo.beSigned(burocrat);
        std::cout << modulo << std::endl;
        modulo.execute(burocrat);
        std::cout << std::endl;
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "-------------------//PRESIDENTIAL NOT SIGNED//----------------------" << std::endl;
    try 
    {
        std::cout << std::endl;
        Bureaucrat burocrat("Obama", 27);
        std::cout << burocrat << std::endl;
        PresidentialPardonForm       modulo(burocrat.getName());
        std::cout << modulo << std::endl;
        modulo.beSigned(burocrat);
        std::cout << modulo << std::endl;
        modulo.execute(burocrat);
        std::cout << std::endl;
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}