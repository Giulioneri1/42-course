/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:10:12 by gneri             #+#    #+#             */
/*   Updated: 2021/11/30 16:47:11 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& form)
{
    (void)form;
    return *this;
}

void    RobotomyRequestForm::FormAction() const
{
    std::cout << "......iiiiiiiiiiiiiiiii......" << std::endl;
    srand(time(NULL));

    int i = rand() % 2;
    if (i == 1)
        std::cout << this->_target << " has been robotomized succesfully" << std::endl;
    else
        std::cout << this->_target << " failed to be robotomized" << std::endl;
}