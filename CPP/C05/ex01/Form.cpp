/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:51:35 by gneri             #+#    #+#             */
/*   Updated: 2021/11/30 12:58:58 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), gradeToSign(1), gradeToExecute(150)
{
    this->_signed = false;
}

Form::Form(const std::string name, const int gts, const int gte) : _name(name), gradeToSign(gts), gradeToExecute(gte)
{
    if (gradeToSign < MAX_GRADE && gradeToExecute < MAX_GRADE)
        throw Form::GradeTooHighException();
    if (gradeToSign > MIN_GRADE && gradeToExecute > MIN_GRADE)
        throw Form::GradeTooLowException();
    this->_signed = false;
}

Form::~Form()
{
    
}

Form::Form(const Form& form) : _name(form._name), gradeToSign(form.gradeToSign), gradeToExecute(form.gradeToExecute)
{
    *this = form;
}

Form&   Form::operator=(const Form& form)
{
    this->_signed = form._signed;    
    return *this;
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Bureaucrat grade is too low.");
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Bureaucrat grade is too high.");
}

const char* Form::AlreadySigned::what() const throw()
{
    return ("the form has already been signed.");
}

const std::string&	Form::getName() const
{
    return this->_name;
}

int Form::getGradeToSign() const
{
    return this->gradeToSign;
}

int Form::getGradeToExe() const
{
    return this->gradeToExecute;
}

bool    Form::getSigned() const
{
    return _signed;
}

void    Form::beSigned(const Bureaucrat& bur)
{
    if (this->getSigned() == true)
        throw Form::AlreadySigned();
    if (bur.getGrade() <= this->gradeToSign)
        this->_signed = true;
    else
        throw Form::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    if (form.getSigned() == false)
        os << "Form: " << form.getName() << " is ready to be signed. A grade higher or equal to " << form.getGradeToSign() << " is required.";
    else
        os << "Form: " << form.getName() << " has been signed and can now be executed";
    return os;
}