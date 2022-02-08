/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:50:58 by gneri             #+#    #+#             */
/*   Updated: 2021/12/01 11:33:46 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    AForm* rrf;
    Intern someRandomIntern;
    std::cout << "------------------//SHRUBBERY FORM SIGNED AND EXECUTED//-----------------------" << std::endl;
    try 
    {
        std::cout << std::endl;
        rrf = someRandomIntern.makeForm("ShrubberyCreationForm", "Obama");
        std::cout << *rrf << std::endl;
        Bureaucrat burocrat("Vins", 130);
        std::cout << burocrat << std::endl;
        burocrat.signForm(*rrf);
        std::cout << *rrf << std::endl;
        burocrat.executeForm(*rrf);
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    delete rrf;
    rrf = NULL;
    std::cout << "-----------------//ROBOTOMY FORM SIGNED NOT EXECUTED//------------------------" << std::endl;
    try 
    {
        std::cout << std::endl;
        rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
        Bureaucrat burocrat("Fgradia", 72);
        std::cout << burocrat << std::endl;
        std::cout << *rrf << std::endl;
        burocrat.signForm(*rrf);
        std::cout << *rrf << std::endl;
        burocrat.executeForm(*rrf);
        std::cout << std::endl;  
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    delete rrf;
}