/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:46:11 by gneri             #+#    #+#             */
/*   Updated: 2021/12/01 10:29:15 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default")
{
    this->_grade = 150;
}

Bureaucrat::Bureaucrat(const std::string name, const int grade) : _name(name)
{
    if (grade < MAX_GRADE)
        throw Bureaucrat::GradeTooHighException();
    if (grade > MIN_GRADE)
        throw Bureaucrat::GradeTooLowException();
    else
        this->_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : _name(obj._name)
{
    *this = obj;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
    this->_grade = obj._grade;

    return *this;
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Error! Grade inserted is too low.");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Error! Grade inserted is too high.");
}

void    Bureaucrat::incrGrade()
{
    if (this->_grade - 1 < MAX_GRADE)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

void    Bureaucrat::decrGrade()
{
    if (this->_grade + 1 > MIN_GRADE)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bur)
{
    os << bur.getName() << " bureaucrat grade " << bur.getGrade();

    return os;
}

const std::string&		Bureaucrat::getName() const
{
    return this->_name;    
}

int 		Bureaucrat::getGrade() const
{
    return this->_grade;
}

void        Bureaucrat::signForm(Form& form) const
{
    try
    {
        form.beSigned(*this);
        std::cout << this->getName() << " signs " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << this->getName() << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
    }
}