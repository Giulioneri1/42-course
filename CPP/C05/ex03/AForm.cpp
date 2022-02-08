/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:51:35 by gneri             #+#    #+#             */
/*   Updated: 2021/11/30 12:58:58 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), gradeToSign(1), gradeToExecute(150)
{
    this->_signed = false;
}

AForm::AForm(const std::string name, const int gts, const int gte) : _name(name), gradeToSign(gts), gradeToExecute(gte)
{
    if (gradeToSign < MAX_GRADE && gradeToExecute < MAX_GRADE)
        throw AForm::GradeTooHighException();
    if (gradeToSign > MIN_GRADE && gradeToExecute > MIN_GRADE)
        throw AForm::GradeTooLowException();
    this->_signed = false;
}

AForm::~AForm()
{
    
}

AForm::AForm(const AForm& form) : _name(form._name), gradeToSign(form.gradeToSign), gradeToExecute(form.gradeToExecute)
{
    *this = form;
}

AForm&   AForm::operator=(const AForm& Aform)
{
    this->_signed = Aform._signed;    
    return *this;
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("grade is too low.");
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("grade is too high.");
}

const char* AForm::AlreadySigned::what() const throw()
{
    return ("the Aform has already been signed.");
}

const char * AForm::FormNotSigned::what() const throw()
{
    return ("you have to sign the form first to execute it.");
}

const std::string&	AForm::getName() const
{
    return this->_name;
}

int AForm::getGradeToSign() const
{
    return this->gradeToSign;
}

int AForm::getGradeToExe() const
{
    return this->gradeToExecute;
}

bool    AForm::getSigned() const
{
    return _signed;
}

void    AForm::beSigned(const Bureaucrat& bur)
{
    if (this->getSigned() == true)
        throw AForm::AlreadySigned();
    if (bur.getGrade() <= this->gradeToSign)
        this->_signed = true;
    else
        throw AForm::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    if (form.getSigned() == false)
        os << "Form: " << form.getName() << " is ready to be signed. A grade higher or equal to " << form.getGradeToSign() << " is required.";
    else
        os << "Form: " << form.getName() << " has been signed and can now be executed";
    return os;
}

void    AForm::execute(const Bureaucrat& executor) const
{
    if (this->getSigned() == false)
        throw AForm::FormNotSigned();
    if (executor.getGrade() <= this->getGradeToExe())
        FormAction();
    else
        throw AForm::GradeTooLowException();
}