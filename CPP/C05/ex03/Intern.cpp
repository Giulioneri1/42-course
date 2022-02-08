/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 09:52:57 by gneri             #+#    #+#             */
/*   Updated: 2021/12/01 11:36:33 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"


Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern& intern)
{
    (void)intern;
}

Intern& Intern::operator=(const Intern& intern)
{
    (void)intern;
    return *this;
}

AForm*  Intern::makeForm(std::string name, std::string target)
{
    AForm *form = NULL;
    
    std::string formType[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    AForm *option[3] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};
    
    for (int i = 0; i < 3; i++)
    {
        if (formType[i] == name)
        {
            std::cout << "Intern creates " << option[i]->getName() << std::endl;
            form = option[i];
        }
        else
            delete option[i];
    }
    if (form == NULL)
        std::cout << "Intern wasn't able to create the form" << std::endl;
    return (form);
}
